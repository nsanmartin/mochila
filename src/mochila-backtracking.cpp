#include <iostream>
#include <numeric>
#include <algorithm>

#include "mochila.h"
using namespace std;


void
resolver_backtracking (vector<item_t> &items, int i, int W, mochila &m,
                       item_sum_t &mejor);

int backtracking (vector<item_t> &items, int W) {
     if (items.size() == 0)
          return 0;
     sort(items.begin(), items.end(),
          [](item_t x, item_t y) {
               return x.first/x.second > y.first/y.second;
          });
     mochila m;
     m.afuera = item_t(0,0);
     item_sum_t mejor_afuera = make_pair(0,0);

     for (int i = 0; i < items.size(); i ++) {
          agregar_item_a_suma(m.total, items[i]);
          if (m.total.second > W)
               agregar_item_a_suma (mejor_afuera, items[i]);
     }
     if (m.total.second <= W) return m.total.first;
     // mejor_afuera.first = m.total.first - mejor_afuera.first;
     // mejor_afuera.second = m.total.second - mejor_afuera.second;
     resolver_backtracking(items, items.size(), W, m, mejor_afuera);

     return m.total.first - mejor_afuera.first;
}


void
resolver_backtracking (vector<item_t> &items, int i, int W, mochila &m,
                       item_sum_t &mejor_afuera)
{
     // poda por optimalidad: "ya saque demasiado valor como para
     // alcanzar el mejor_afuera observado"
     if (m.afuera.first > mejor_afuera.first || m.adentro.second > W) 
          return;

     if (i == 0) {  // ultimo
          mejor_afuera  = m.afuera;          
     } else {
          mochila m_con_iesimo(m);
          agregar_item_a_suma(m.adentro, items[i - 1]);
          resolver_backtracking(items, i - 1, W, m, mejor_afuera);
          agregar_item_a_suma(m_con_iesimo.afuera, items[i - 1]);
          resolver_backtracking(items, i - 1, W, m_con_iesimo, mejor_afuera);
     }
}




