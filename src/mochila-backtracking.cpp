#include <iostream>
#include <numeric>
#include <algorithm>

#include "mochila.h"
using namespace std;


void
resolver_backtracking (vector<item_t> &items, int i, int W,
                        item_sum_t &mochila_actual, item_sum_t &mejor,
                       item_sum_t &totales, item_sum_t suma_hasta_aca);



int backtracking (vector<item_t> &items, int W) {
     sort(items.begin(), items.end(),
          [](item_t x, item_t y) {
               return x.first/ x.second < y.first / y.second;
          });
     
     item_sum_t mochila_actual = make_pair(0,0);
     item_sum_t suma_hasta_aca = make_pair(0,0);
     item_sum_t mejor;
     item_sum_t totales;
     for (int i = 0; i < items.size(); i ++) {
          agregar_item_a_suma(totales, items[i]);
          if (mejor.second + items[i].second <= W)
               agregar_item_a_suma (mejor, items[i]);
     }
     mejor.first = totales.first - mejor.first;
     mejor.second = totales.second - mejor.second;
     resolver_backtracking(items, 0, W, mochila_actual, mejor, totales,
          suma_hasta_aca);
     return totales.first - mejor.first;
}


void
resolver_backtracking (vector<item_t> &items, int i, int W,
                        item_sum_t &mochila_actual, item_sum_t &mejor,
                       item_sum_t &totales, item_sum_t suma_hasta_aca)
{
     // poda por optimalidad: "ya saque demasiado valor como para
     // alcanzar el mejor observado"
     int beneficio_no_observado = totales.first - suma_hasta_aca.first;
     int beneficio_en_mochila =
          suma_hasta_aca.first - mochila_actual.first;
     agregar_item_a_suma(suma_hasta_aca, items[i]);
     int mejor_beneficio_obervado = totales.first - mejor.first;
     if (beneficio_no_observado + beneficio_en_mochila
         < mejor_beneficio_obervado)
          return;
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
     resolver_backtracking(
          items, i + 1, W, mochila_actual, mejor, totales,
          suma_hasta_aca);

     // aca si saco el i-esimo, solo si no saque suficiente como para
     // que seguir sacando perjudique el beneficio 
     if (totales.second - actual_copia.second <= W)
          return;
     
     agregar_item_a_suma(actual_copia, items[i]);
     resolver_backtracking(
          items, i + 1, W, actual_copia, mejor, totales, suma_hasta_aca);
     return;
}
