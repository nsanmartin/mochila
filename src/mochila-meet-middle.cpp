#include <iostream>
#include <numeric>
#include <algorithm>
#include "mochila.h"

using namespace std;
vector<item_sum_t>
conjunto_de_partes(int desde, int hasta, vector<item_t>&items, int W) ;
void agregar_item_a_suma(item_sum_t &x, item_t const &i);
item_sum_t
mochila_optima (vector<item_sum_t> A, vector<item_sum_t> B_filtrada, int W);
vector<item_sum_t>
filtrar_mochilas_pesadas(vector<item_sum_t> &mochilas) ;

item_sum_t
buscar_combinacion_optima(vector<item_sum_t> &B_ordenada, int tope);


int meet_middle (vector<item_t> &items, int W) {
     int n = items.size();
     
     vector<item_sum_t> A = conjunto_de_partes(0, n/2, items, W);
     vector<item_sum_t> B = conjunto_de_partes(n/2, n, items, W);
     // ordeno por peso
     sort(B.begin(), B.end(),
          [](item_t x, item_t y) { return x.second < y.second; });

     vector<item_sum_t> B_filtrado = filtrar_mochilas_pesadas(B);
     return mochila_optima(A, B_filtrado, W).first;
}

vector<item_sum_t>
conjunto_de_partes(int desde, int hasta, vector<item_t>&items, int W) {
     vector<item_sum_t> partes;
     for (int i = desde; i < hasta; i++) {
          if (items[i].second > W)
               continue;
          int partes_size = partes.size();
          partes.push_back(items[i]);
          for (int j = 0; j < partes_size; j++) {
               item_sum_t x = partes[j];
               agregar_item_a_suma(x, items[i]);
               if (x.second <= W)
                    partes.push_back(x);
          }
     }
     return partes;
}



// ver paper [2]
vector<item_sum_t>
filtrar_mochilas_pesadas(vector<item_sum_t> &mochilas) {
     vector<item_sum_t> res;
     auto p = make_pair(0,0);
     res.push_back(p);
     
     for (int i = 0; i < mochilas.size(); i++) {
          if (res.back().first < mochilas[i].first)
               res.push_back(mochilas[i]);
     }
     return res;
}

item_sum_t
mochila_optima (vector<item_sum_t> A, vector<item_sum_t> B_filtrada, int W) {
     item_sum_t mejor_B = B_filtrada.back();
     if (A.size() == 0)
          return mejor_B;
     item_sum_t optima = A[0];
     item_sum_t b = buscar_combinacion_optima(B_filtrada, W - optima.second);
     if (b.second + optima.second <= W) {
          optima.second += b.second;
          optima.first += b.first;
     }
     if (optima.first < mejor_B.first)
          optima = mejor_B;
     for (int i = 1; i < A.size(); i++) {
          item_sum_t a = A[i];
          b = buscar_combinacion_optima(B_filtrada, W - a.second);
          if (b.second + a.second <= W) {
               a.second += b.second;
               a.first += b.first;
          } else if (b.first > a.first) {
               a = b;
          }

          if (optima.first < a.first) 
               optima = a;
     }
     return optima;
}

item_sum_t
buscar_combinacion_optima(vector<item_sum_t> &B, int tope)
{
     // precondicion (0, 0) in B, tope >= 0
     unsigned long desde = 0;
     unsigned long hasta = B.size();
     unsigned long n = hasta;
     unsigned med;
     
     // if (B[B.size()-1].second <= tope) {
     //      B[B.size()-1];
     // }

     while (desde < hasta - 1) {
          med = (desde + hasta) / 2;
          if (B[med].second <= tope) {
               desde = med;
          }
          else
               hasta = med;
     }

     if (hasta < n && B[hasta].second <= tope)
          return B[hasta];
     return B[desde];
}
