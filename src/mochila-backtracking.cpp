#include <iostream>
#include <numeric>
#include <algorithm>

#include "mochila.h"
using namespace std;

typedef struct mochila {
     item_sum_t actual;
     item_sum_t mejor;
     item_sum_t total;
} mochila;


void
resolver_backtracking (vector<item_t> &items, int i, int W,
                        item_sum_t &mochila_actual, item_sum_t &mejor,
                       item_sum_t &totales);

void
resolver_backtracking2 (vector<item_t> &items, int i, int W,
                        mochila &m, vector<item_sum_t> &acum);



int backtracking2 (vector<item_t> &items, int W) {
     sort(items.begin(), items.end(),
          [](item_t x, item_t y) {
               return x.first > y.first;
          });
     mochila m;
     m.actual = make_pair(0,0);
     //item_sum_t total;
     vector<item_sum_t>acum;
     m.mejor = make_pair(0,0);

     for (int i = 0; i < items.size(); i ++) {
          agregar_item_a_suma(m.total, items[i]);
          acum.push_back(m.total);
          if (m.mejor.second + items[i].second <= W)
               agregar_item_a_suma (m.mejor, items[i]);
     }
     if (m.total.second <= W) return m.total.first;
     m.mejor.first = m.total.first - m.mejor.first;
     m.mejor.second = m.total.second - m.mejor.second;
     resolver_backtracking2(items, 0, W, m, acum);

     return m.total.first - m.mejor.first;
}

int backtracking (vector<item_t> &items, int W) {
     sort(items.begin(), items.end(),
          [](item_t x, item_t y) {
               return x.first > y.first ;
          });
     
     item_sum_t actual = make_pair(0,0);
     item_sum_t total;
     item_sum_t mejor = make_pair(0,0);

     for (int i = 0; i < items.size(); i ++) {
          agregar_item_a_suma(total, items[i]);
          if (mejor.second + items[i].second <= W)
               agregar_item_a_suma (mejor, items[i]);
     }
     if (total.second <= W) return total.first;
     mejor.first = total.first - mejor.first;
     mejor.second = total.second - mejor.second;
     resolver_backtracking(items, 0, W, actual, mejor, total);
     return total.first - mejor.first;
}


void
resolver_backtracking (vector<item_t> &items, int i, int W,
                        item_sum_t &actual, item_sum_t &mejor,
                       item_sum_t &total)
{
     // poda por optimalidad: "ya saque demasiado valor como para
     // alcanzar el mejor observado"
     if (actual.first > mejor.first)
          return;

     if (i == items.size() - 1) {  // ultimo
          item_sum_t sacando_i(actual);
          agregar_item_a_suma(sacando_i, items[i]); // "saco i"
          // ni sacando i estoy debajo del tope.
          if (W < total.second - sacando_i.second) 
               return;

          // mejor es menor, porque es lo que se saca
          if (mejor.first > sacando_i.first)
               mejor = sacando_i;

          // dejando i
          if (W < total.second - actual.second)
               return;
          if (mejor.first > actual.first)
               mejor = actual;
          return; 
     }
     item_sum_t actual_copia(actual);
     // aca "no saco" el i-esimo elemento
     resolver_backtracking(
               items, i + 1, W, actual, mejor, total);

     // aca si saco el i-esimo, solo si no saque suficiente como para
     // que seguir sacando perjudique el beneficio 
     // if (total.second - actual_copia.second <= W)
     //      return;
     
     agregar_item_a_suma(actual_copia, items[i]);
     //?
     // if (actual_copia.first > mejor.first)
     //      return;

     resolver_backtracking(
          items, i + 1, W, actual_copia, mejor, total);
     return;
}

void
resolver_backtracking2  (vector<item_t> &items, int i, int W,
                         mochila &m, vector<item_sum_t> &acum)
{
     // poda por optimalidad: "ya saque demasiado valor como para
     // alcanzar el mejor observado"
     if (m.actual.first > m.mejor.first) {
          return;
     }
     if (i == items.size() - 1) {  // ultimo
          item_sum_t sacando_i(m.actual);
          agregar_item_a_suma(sacando_i, items[i]); // "saco i"
          // ni sacando i estoy debajo del tope.
          if (W < m.total.second - sacando_i.second) 
               return;

          // mejor es menor, porque es lo que se saca
          if (m.mejor.first > sacando_i.first)
               m.mejor = sacando_i;

          // dejando i
          if (W < m.total.second - m.actual.second)
               return;
          if (m.mejor.first > m.actual.first)
               m.mejor = m.actual;
          return; 
     }
     item_sum_t actual_copia(m.actual);
     // aca "no saco" el i-esimo elemento
     if (acum[i].second - m.actual.second <= W) 
          resolver_backtracking2(
               items, i + 1, W, m, acum);

     // aca si saco el i-esimo, solo si no saque suficiente como para
     // que seguir sacando perjudique el beneficio 
     // if (total.second - actual_copia.second <= W)
     //      return;
     
     agregar_item_a_suma(actual_copia, items[i]);
     m.actual = actual_copia;
     //?
     // if (actual_copia.first > mejor.first)
     //      return;

     resolver_backtracking2(
          items, i + 1, W, m, acum);
     return;
}



