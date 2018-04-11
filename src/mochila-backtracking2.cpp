#include <iostream>
#include <numeric>
#include <algorithm>

#include "mochila.h"
using namespace std;

void
resolver_backtracking2 (vector<item_t> &items, int i, int W, item_sum_t &m,
                        int &mejor);



int mochila_gol_ent(vector<item_t>&items, int desde, int tope);

int backtracking2 (vector<item_t> &items, int W) {
     sort(items.begin(), items.end(), [] (item_t x, item_t y) {
               return x.first/x.second > y.first/y.second ;
          });
     item_sum_t m = item_t(0,0);
     item_sum_t total = item_sum_t(0,0);
     for (int i = 0; i < items.size(); i ++) {
          agregar_item_a_suma(total, items[i]);
     }
     if (total.second <= W) return total.first;
     int mejor = 0;
     resolver_backtracking2(items, items.size(), W, m, mejor);
     return mejor;
}

void
resolver_backtracking2 (vector<item_t> &items, int i, int W, item_sum_t &m,
                       int &mejor)
{
     if (m.first + mochila_gol_ent(items, i, W-m.second) < mejor
         || m.second > W) 
          return;
     if (i == 0) {  // ultimo
          mejor  = m.first;          
     } else {
          item_sum_t m_sin_iesimo(m);
          agregar_item_a_suma(m, items[i - 1]);
          resolver_backtracking2(items, i - 1, W, m, mejor);
          resolver_backtracking2(items, i - 1, W, m_sin_iesimo, mejor);
     }
}

int mochila_gol_ent(vector<item_t>&items, int hasta, int tope) {
     item_sum_t suma = item_sum_t(0, 0);
     for (int i = 0; i < hasta ; i++) {
          if (suma.second + items[i].second > tope) {
               suma.first
                    += items[i].first * (tope - suma.second) / items[i].second;
               break;
          }
          agregar_item_a_suma(suma, items[i]);
     }
     return suma.first;
}
