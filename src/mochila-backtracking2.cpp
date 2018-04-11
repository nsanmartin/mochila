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
               return x.first/x.second < y.first/y.second ;
          });
     item_sum_t m = item_t(0,0);
     item_sum_t total = item_sum_t(0,0);
     for (int i = 0; i < items.size(); i ++) {
          agregar_item_a_suma(total, items[i]);
     }
     if (total.second <= W) return total.first;
     int mejor = 0;
     resolver_backtracking2(items, items.size(), W, m, mejor);
     cout << "vta";
     return mejor;
}

void
resolver_backtracking2 (vector<item_t> &items, int i, int W, item_sum_t &m,
                       int &mejor)
{
     cout << "\ni es " <<  i << endl;
     if (i == 0) {
          // cout << "i == 0\t";
          // cout << "m : (" << m.first << "," << m.second << ")" << endl;
          if (m.first > mejor && m.second <= W)
               mejor  = m.first;          
     } else {
          if (m.second > W)
               return;
          int gol = mochila_gol_ent(items, i-1, W - m.second);
          if (m.second > W || gol + m.first < mejor) {//|| m.first + gol < mejor) {
               cout << "___\\";
               return;
          }
          //      // cout << "poda opt:\t";
          //      // cout << "m : (" << m.first << "," << m.second << ")";
          //      // cout << "\n\t i: "<< i << endl;
          //      // cout << "\n\t m.first: " << m.first << "\t m.second: " << m.second ;
              
          //      // cout << "\n\t mochi_gl: " << mochila_gol_ent(items, i-1, W-m.second) ;
          //      // cout << "\n\t mejor: " << mejor;
          //      // cout << endl;
          //      return;
          //} else {
          item_sum_t m_sin_iesimo(m);
          agregar_item_a_suma(m, items[i - 1]);
          resolver_backtracking2(items, i - 1, W, m, mejor);
          resolver_backtracking2(items, i - 1, W, m_sin_iesimo, mejor);
     }
}


int mochila_gol_ent(vector<item_t>&items, int i, int tope) {
     cout << "\n\t tope : " << tope;
     cout << "\t i: " << i;
     int benef = 0;
     int peso = 0;
     for (;i >= 0; i--) {
          if (peso + items[i].second > tope) {
               cout << "\nBEGIN::::::::\n";
               cout << "tope: " << tope << "\tsuma_w: " << peso
                    << "\t peso_ult: " << items[i].second
                    << "\t tope- pesoAc: " << (tope - peso)
                    << endl;
               int parte = (items[i].first * (tope - peso)) / items[i].second;
               benef  += parte + 1;//items[i].first;

               cout << "::::::::::END\n";
               break;
          }
          benef += items[i].first;
          peso += items[i].second;
     }
     cout << "\t benef: " << benef << endl;
     return benef;
}
