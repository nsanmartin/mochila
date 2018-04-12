#include <iostream>
#include <numeric>
#include <algorithm>

#include "mochila.h"
using namespace std;

void
resolver_backtracking2 (vector<item_t> &items, int i, int W, item_sum_t &m,
                        int &mejor);



double mochila_gls(vector<item_t>&items, int desde, int tope);

int backtracking2 (vector<item_t> &items, int W) {
     sort(items.begin(), items.end(), [] (item_t x, item_t y) {
               return (double)x.first/(double)x.second
                    < (double)y.first/(double)y.second ;
          });
     item_sum_t m = item_t(0,0);
     int mejor = 0;
     resolver_backtracking2(items, items.size(), W, m, mejor);
     return mejor;
}

void
resolver_backtracking2 (vector<item_t> &items, int i, int W, item_sum_t &m,
                        int &mejor)
{
     double cota_gls = mochila_gls(items, i-1, W - m.second);
     if (m.second > W || cota_gls + (double) m.first < (double)mejor)
          return;
     if (i == 0) 
          mejor = m.first;
     else {
          item_sum_t m_sin_iesimo(m);
          resolver_backtracking2(items, i - 1, W, m_sin_iesimo, mejor);
          agregar_item_a_suma(m, items[i - 1]);
          resolver_backtracking2(items, i - 1, W, m, mejor);
     }
}


double mochila_gls(vector<item_t>&items, int i, int tope) {
     double benef = 0;
     int peso = 0;
     for (;i >= 0 && peso < tope; i--) {
          if (peso + items[i].second <= tope) {
               benef += (double) items[i].first;
               peso += items[i].second;
          } else {
               double parte = (double)items[i].first
                    *(double) ((tope-peso)/(double)items[i].second);
               benef += parte;
               peso += items[i].second;
               break;
          }
     }
     // cout << benef << endl;
     return benef;
}
