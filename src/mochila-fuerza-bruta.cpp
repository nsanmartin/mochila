#include <iostream>
#include <numeric>
#include <algorithm>

#include "mochila.h"
using namespace std;


void
resolver_fuerza_bruta4 (vector<item_t> &items, int i, int W,
                        item_sum_t &mochila_actual, item_sum_t &mejor,
                        item_sum_t &totales);



void
resolver_fuerza_bruta (vector<item_t> &items, int i, int W, mochila &m,
                       item_sum_t &mejor_afuera);

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



int fuerza_bruta4 (vector<item_t> &items, int W) {
     if (items.size() == 0)
          return 0;
     item_sum_t mochila_actual = make_pair(0,0);
     item_sum_t totales;
     for (int i = 0; i < items.size(); i ++) {
          agregar_item_a_suma(totales, items[i]);
          // if (mejor.second + items[i].second <= W)
          //      agregar_item_a_suma (mejor, items[i]);
     }
     item_sum_t mejor(totales);

     // mejor.first = totales.first - mejor.first;
     // mejor.second = totales.second - mejor.second;
     resolver_fuerza_bruta4(items, 0, W, mochila_actual, mejor, totales);
     return totales.first - mejor.first;
}




void
resolver_fuerza_bruta4 (vector<item_t> &items, int i, int W,
                        item_sum_t &mochila_actual, item_sum_t &mejor,
                        item_sum_t &totales)
{

     if (i == items.size() - 1) {  // ultimo

          item_sum_t sacando_i(mochila_actual);
          agregar_item_a_suma(sacando_i, items[i]); // "saco i"
          // ni sacando i estoy debajo del tope.
          if (W < totales.second - sacando_i.second) 
               return;

          // mejor es menor, porque es lo que se saca
          if (mejor.first > sacando_i.first)
               mejor = sacando_i;

          // dejando i
          if (W < totales.second - mochila_actual.second)
               return;
          if (mejor.first > mochila_actual.first)
               mejor = mochila_actual;
          return; 
     }
     item_sum_t actual_copia(mochila_actual);
     // aca "no saco" el i-esimo elemento
     resolver_fuerza_bruta4(
          items, i + 1, W, mochila_actual, mejor, totales);

     // aca si saco el i-esimo, solo si no saque suficiente como para
     // que seguir sacando perjudique el beneficio 
     // if (totales.second - actual_copia.second <= W)
     //      return;
     
     agregar_item_a_suma(actual_copia, items[i]);
     resolver_fuerza_bruta4(
          items, i + 1, W, actual_copia, mejor, totales);
     return;
}




int fuerza_bruta (vector<item_t> &items, int W) {
     if (items.size() == 0)
          return 0;
     sort(items.begin(), items.end(),
          [](item_t x, item_t y) {
               return x.first > y.first;
          });
     mochila m;
     m.afuera = item_t(0,0);
     item_sum_t mejor_afuera = make_pair(0,0);

     for (int i = 0; i < items.size(); i ++) {
          agregar_item_a_suma(m.total, items[i]);
          if (mejor_afuera.second + items[i].second <= W)
               agregar_item_a_suma (mejor_afuera, items[i]);
     }
     if (m.total.second <= W) return m.total.first;
     mejor_afuera.first = m.total.first - mejor_afuera.first;
     mejor_afuera.second = m.total.second - mejor_afuera.second;
     resolver_fuerza_bruta(items, items.size(), W, m, mejor_afuera);

     return m.total.first - mejor_afuera.first;
}


void
resolver_fuerza_bruta (vector<item_t> &items, int i, int W, mochila &m,
                       item_sum_t &mejor_afuera)
{
     // poda por optimalidad: "ya saque demasiado valor como para
     // alcanzar el mejor_afuera observado"

     if (i == 0) {// ultimo
          if (!(m.afuera.first > mejor_afuera.first || m.adentro.second > W))
               mejor_afuera  = m.afuera;
     } else {
          mochila m_con_iesimo(m);
          agregar_item_a_suma(m.adentro, items[i - 1]);
          resolver_fuerza_bruta(items, i - 1, W, m, mejor_afuera);
          agregar_item_a_suma(m_con_iesimo.afuera, items[i - 1]);
          resolver_fuerza_bruta(items, i - 1, W, m_con_iesimo, mejor_afuera);
     }
}




