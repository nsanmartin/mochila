#include <iostream>
#include <vector>
#include <numeric>
#include <utility>

using namespace std;
void
resolver_fuerza_bruta2 (vector<int> &pre, vector<int> &conj, int W,
                        pair<int,int> &totales,
                        vector<pair<int,int>> &items,
                        vector<int> &beneficios) ;

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


// obtiene peso y beneficio de un subconjunto conj de items
// O(n) , n == len(conj)
pair<int,int> calcular_sumas(vector<pair<int,int>>&items, vector<int>&conj) {
     pair<int,int> res(0,0);
     for (int& x : conj ) {
          res.first += items[x].first; 
          res.second += items[x].second;
     }
     return res;
}


int calcular_precio(vector<pair<int,int>>&items, vector<int>&conj) {
     int res = 0;
     for (int& x : conj ) { res += items[x].first; }
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
     resolver_fuerza_bruta(pre, conj, W, peso_total, precios, weights, beneficios);
     for (int x : precios) { precio_total += x; }
     int precio_sacado = precio_total;

     for (int x : beneficios) {
          if (precio_sacado > x) 
               precio_sacado = x;
     }

     return precio_total - precio_sacado;
     
}

int fuerza_bruta2 (vector<pair<int,int>> &items, int W) {

     vector<int> pre;
     vector<int> conj(items.size());
     vector<int> beneficios;
     iota(conj.begin(), conj.end(), 0);
     pair<int, int> totales = calcular_sumas(items, conj);

     resolver_fuerza_bruta2(pre, conj, W, totales, items, beneficios);

     int precio_sacado = totales.first;
     for (int x : beneficios) {
          if (precio_sacado > x) 
               precio_sacado = x;
     }
     return totales.first - precio_sacado;
     
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



void
resolver_fuerza_bruta2 (vector<int> &pre, vector<int> &conj, int W,
                        pair<int,int> &totales,
                        vector<pair<int,int>> &items,
                        vector<int> &beneficios) {

     pair<int,int> suma_pre = calcular_sumas(items, pre);
     if (conj.size() == 1) {

          pair<int,int> suma_pre_conj= calcular_sumas(items, conj);
          suma_pre_conj.first += suma_pre.first;
          suma_pre_conj.second += suma_pre.second;
          
          // solo vale la solución si lo que saco pesa suficiente como
          // para que lo que queda no supere W
          if (W < totales.second - suma_pre_conj.second) 
               return;
          beneficios.push_back(suma_pre_conj.first);

          if (W < totales.second - suma_pre.second)
               return;
          beneficios.push_back(suma_pre.first);
          return; 
     }
     vector<int> pre_copia(pre);
     //vector<int> pre_0(pre);
     vector<int> conj_copia(conj);
     int head = conj.back();
     pre_copia.push_back(head);
     conj_copia.pop_back();

     resolver_fuerza_bruta2(
          pre, conj_copia, W, totales, items, beneficios);

     // si ya saque suficiente para obtener una solucion, no sigo sacando
     if (totales.second - suma_pre.second <= W)
          return;
     resolver_fuerza_bruta2(
          pre_copia, conj_copia, W, totales, items, beneficios);
     return;
}
