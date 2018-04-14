#include <iostream>
#include <numeric>
#include <algorithm>

#include "mochila.h"
using namespace std;


void
resolver_backtracking0 (vector<item_t> &items, int i, int W, mochila &m,
                       item_sum_t &mejor);

int backtracking0 (vector<item_t> &items, int W) {
     mochila m;
     m.afuera = item_t(0,0);
     item_sum_t total = item_sum_t(0,0);
     for (int i = 0; i < items.size(); i ++) {
          agregar_item_a_suma(total, items[i]);
     }
     if (total.second <= W) return total.first;
     item_sum_t mejor_afuera = item_sum_t(total);
     resolver_backtracking0(items, items.size(), W, m, mejor_afuera);

     return total.first - mejor_afuera.first;
}


void
resolver_backtracking0 (vector<item_t> &items, int i, int W, mochila &m,
                       item_sum_t &mejor_afuera)
{
     // poda por optimalidad: "ya saque demasiado valor como para
     // alcanzar el mejor_afuera observado"
     if (m.afuera.first > mejor_afuera.first || m.adentro.second > W) 
          return;

     if (i == 0) {  // ultimo
          mejor_afuera  = m.afuera;          
     } else {
          mochila m_sin_iesimo(m);
          agregar_item_a_suma(m.adentro, items[i - 1]);
          resolver_backtracking0(items, i - 1, W, m, mejor_afuera);
          agregar_item_a_suma(m_sin_iesimo.afuera, items[i - 1]);
          resolver_backtracking0(items, i - 1, W, m_sin_iesimo,
                                mejor_afuera);
     }
}




