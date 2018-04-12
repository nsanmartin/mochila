#include <iostream>
#include <numeric>
#include <algorithm>

#include "mochila.h"
using namespace std;

void
resolver_backtracking2 (vector<item_t> &items, int i, int W, item_sum_t &m,
                        int &mejor);



double mochila_gol_ent(vector<item_t>&items, int desde, int tope);

int backtracking2 (vector<item_t> &items, int W) {
     sort(items.begin(), items.end(), [] (item_t x, item_t y) {
               return x.first/x.second < y.first/y.second ;
          });
     // for (int i = 0; i < items.size(); i++)
     //      cout << items[i].first << "/" << items[i].second << endl;
     item_sum_t m = item_t(0,0);
     // item_sum_t total = item_sum_t(0,0);
     // for (int i = 0; i < items.size(); i ++) {
     //      agregar_item_a_suma(total, items[i]);
     // }
     // if (total.second <= W) return total.first;
     int mejor = 0;
     resolver_backtracking2(items, items.size(), W, m, mejor);
     return mejor;
}

void
resolver_backtracking2 (vector<item_t> &items, int i, int W, item_sum_t &m,
                       int &mejor)
{
     if (m.second > W)
          return;
     if (i == 0) {
          if (m.first > mejor && m.second <= W) {
               mejor = m.first;
          }
     } else {
          // cout << "+++++++++++++++++++++++++++++++++ i: " << i
          // << "(" << items[i-1].first << "/" << items[i-1].second << ")"
          // << endl;

          double gol = mochila_gol_ent(items, i-1, W - m.second);
          // cout << "gol ppara i: " << i << " = " << (double)gol
          //      << "\t tope: " << W - m.second<< endl;
          if (gol + (double) m.first < (double)mejor) {
               cout << "gol + (double) m.first < (double)mejor"
                    << gol << " + " <<  (double) m.first
                    << " < " << (double)mejor
                    << endl;
               return;
          }
          item_sum_t m_sin_iesimo(m);
          resolver_backtracking2(items, i - 1, W, m_sin_iesimo, mejor);
          agregar_item_a_suma(m, items[i - 1]);
          resolver_backtracking2(items, i - 1, W, m, mejor);
     }
}


double mochila_gol_ent(vector<item_t>&items, int i, int tope) {
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
