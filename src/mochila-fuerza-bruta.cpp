#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
void
resolver_fuerza_bruta(vector<int> &pre, vector<int> &conj,
                      int W, int peso_total,
                      vector<int> &ps, vector<int> &ws,
                      vector<int> &beneficios) ;

int calcular_suma(vector<int>&ps,vector<int>&conj) {
     int res = 0;
     for (int& x : conj ) { res += ps[x]; }
     return res;
}

int fuerza_bruta (vector<int> precios, vector<int>weights, int W) {

     vector<int> pre;
     vector<int> conj(weights.size());
     vector<int> beneficios;
     int peso_total = 0;
     int precio_total = 0;
     iota(conj.begin(), conj.end(), 0);
     for (int x : weights) { peso_total += x; }
     resolver_fuerza_bruta(pre, conj, W, peso_total, precios, weights,
                           beneficios);
     for (int x : precios) { precio_total += x; }
     int precio_sacado = precio_total;

     for (int x : beneficios) {
          if (precio_sacado > x) 
               precio_sacado = x;
     }

     return precio_total - precio_sacado;
     
}

int print_vec(vector<int> v, string str) {
     int suma = 0;
     cout << str;
     for (int x : v) {
          suma += x;
          cout << x << " " ;
     }
     cout << endl;
     return suma;
}

void
resolver_fuerza_bruta (vector<int> &pre, vector<int> &conj,
                       int W, int peso_total,
                       vector<int> &ps, vector<int> &ws,
                       vector<int> &beneficios) {

     int peso_pre = calcular_suma(ws, pre);
     if (conj.size() == 1) {
          int benef_pre = calcular_suma(ps, pre);
          int benef_pre_conj = benef_pre + calcular_suma(ps, conj);
          int peso_pre_conj = peso_pre + calcular_suma(ws, conj);
          // solo vale la solución si lo que saco pesa suficiente como
          // para que lo que queda no supere W
          if (W < peso_total - peso_pre_conj) 
               return;
          beneficios.push_back(benef_pre_conj);

          if (W < peso_total - peso_pre)
               return;
          beneficios.push_back(benef_pre);
          return; 
     }
     vector<int> pre_copia(pre);
     vector<int> pre_0(pre);
     vector<int> conj_copia(conj);
     int head = conj.back();
     pre_copia.push_back(head);

     conj_copia.pop_back();
     resolver_fuerza_bruta(pre_0, conj_copia, W, peso_total,
                           ps, ws, beneficios);
     // si ya saque suficiente para obtener una solucion, no sigo sacando
     if (peso_total - peso_pre <= W)
          return;
     resolver_fuerza_bruta(pre_copia, conj_copia,
                           W, peso_total, ps, ws, beneficios);
     return;
}
