#include <iostream>
#include <numeric>
#include <algorithm>
#include "mochila.h"

using namespace std;
vector<item_sum_t>
conjunto_de_partes(int desde, int hasta, vector<item_t>&items, int W) ;
void agregar_item_a_suma(item_sum_t &x, item_t const &i);
item_sum_t
mochila_optima (vector<item_sum_t> A, vector<item_sum_t> B_filtrada,
                int W);
vector<item_sum_t>
filtrar_mochilas_pesadas(vector<item_sum_t> &mochilas) ;

item_sum_t
buscar_combinacion_optima(vector<item_sum_t> &B_ordenada, int tope);


int meet_middle (vector<item_t> &items, int W) {
     int n = items.size();
     if (n == 0)
          return 0;
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
mochila_optima (vector<item_sum_t> A, vector<item_sum_t> B_filtrada,
                int W) {
     // precondiciones:
     // 1: (0, 0) pertence a B_filtrada
     // 2: x en B_filtrada => x.peso <= W
     // 3: B_filtrada esta ordenada
     item_sum_t optima = B_filtrada.back();
     for (int i = 0; i < A.size(); i++) {
          item_sum_t a = A[i];
          item_sum_t b = buscar_combinacion_optima(B_filtrada,
                                                   W - a.second);
          if (b.second + a.second <= W) 
               combinar_sumas(a, b);
          else if (b.first > a.first) 
               a = b;
          
          if (optima.first < a.first) 
               optima = a;
     }
     return optima;
}

// busqueda binaria de mayor x en B tal que x.peso <= tope
item_sum_t
buscar_combinacion_optima(vector<item_sum_t> &B, int tope)
{
     // precondicion (0, 0) pertenece a B, tope >= 0
     unsigned long desde = 0;
     unsigned long hasta = B.size();
     unsigned long n = hasta;
     unsigned med;
     
     while (desde < hasta - 1) {
          med = (desde + hasta) / 2;
          if (B[med].second <= tope)
               desde = med;
          else
               hasta = med;
     }
     if (hasta < n && B[hasta].second <= tope)
          return B[hasta];
     return B[desde];
}
