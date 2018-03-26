#include <iostream>
#include <numeric>
#include <algorithm>
#include "mochila.h"

using namespace std;
vector<item_sum_t>
conjunto_de_partes(int desde, int hasta, vector<item_t>&items, int W) ;
void agregar_item_a_suma(item_sum_t x, item_t i);
int meet_middle (vector<item_t> &items, int W) {
     int n = items.size();
     
     vector<item_sum_t> A = conjunto_de_partes(0, n/2, items, W);
     vector<item_sum_t> B = conjunto_de_partes(n/2, n, items, W);
     sort(B.begin(), B.end(), [](item_t x, item_t y) {
               return x.first * y.second < y.first * x.second;
          });
}

vector<item_sum_t>
conjunto_de_partes(int desde, int hasta, vector<item_t>&items, int W) {
     vector<item_sum_t> partes;

     for (int i = desde; i < hasta; i++) {
          int partes_size = partes.size();
          for (int j = 0; i < partes_size; i++) {
               item_sum_t x = partes[j];
               agregar_item_a_suma(x, items[i]);
               if (x.second <= W)
                    partes.push_back(x);
          }
     }
     return partes;
}

void agregar_item_a_suma(item_sum_t x, item_t i) {
     //Todo
};
