#include <iostream>
#include <numeric>

#include "mochila.h"
using namespace std;
void
resolver_backtracking (vector<int> &pre, vector<int> &conj, int W,
                        item_sum_t &totales,
                        vector<item_t> &items,
                        vector<int> &beneficios) ;


int calcular_suma(vector<int>&ps,vector<int>&conj) {
     int res = 0;
     for (int& x : conj ) { res += ps[x]; }
     return res;
}


// obtiene peso y beneficio de un subconjunto conj de items
// O(n) , n == len(conj)
item_sum_t calcular_sumas(vector<pair<int,int>>&items, vector<int>&conj) {
     item_sum_t res(0,0);
     for (int& x : conj ) {
          res.first += items[x].first; 
          res.second += items[x].second;
     }
     return res;
}


int calcular_precio(vector<item_t>&items, vector<int>&conj) {
     int res = 0;
     for (int& x : conj ) { res += items[x].first; }
     return res;
}

int backtracking (vector<item_t> &items, int W) {

     vector<int> pre;
     vector<int> conj(items.size());
     vector<int> beneficios;
     iota(conj.begin(), conj.end(), 0);
     item_sum_t totales = calcular_sumas(items, conj);

     resolver_backtracking(pre, conj, W, totales, items, beneficios);

     int precio_sacado = totales.first;
     for (int x : beneficios) {
          if (precio_sacado > x) 
               precio_sacado = x;
     }
     return totales.first - precio_sacado;
     
}



// int print_vec(vector<int> v, string str) {
//      int suma = 0;
//      cout << str;
//      for (int x : v) {
//           suma += x;
//           cout << x << " " ;
//      }
//      cout << endl;
//      return suma;
// }


void
resolver_backtracking (vector<int> &pre, vector<int> &conj, int W,
                        item_sum_t &totales,
                        vector<item_t> &items,
                        vector<int> &beneficios) {

     item_sum_t suma_pre = calcular_sumas(items, pre);
     if (conj.size() == 1) { // es el último item

          item_sum_t suma_pre_conj = calcular_sumas(items, conj);
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
