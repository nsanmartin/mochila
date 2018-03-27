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

void agregar_item_a_suma(item_sum_t &x, item_t const &i) {
     x.first += i.first;
     x.second += i.second;
};


// ver paper [2]
vector<item_sum_t>
filtrar_mochilas_pesadas(vector<item_sum_t> &mochilas) {
     vector<item_sum_t> res;
     if (mochilas.size() == 0) {
          auto p = make_pair(0,0);
          res.push_back(p);
          return res;
     }
     res.push_back(mochilas[0]);
     for (int i = 1; i < mochilas.size(); i++) {
          if (res.back().first < mochilas[i].first)
               res.push_back(mochilas[i]);
     }
     return res;
}

item_sum_t
mochila_optima (vector<item_sum_t> A, vector<item_sum_t> B_filtrada, int W) {
     if (A.size() == 0)
          return B_filtrada.back();
     item_sum_t optima = A[0];
     item_sum_t b = buscar_combinacion_optima(B_filtrada, W - optima.second);
     if (b.second + optima.second <= W) {
          optima.second += b.second;
          optima.first += b.first;
     }
     for (int i = 1; i < A.size(); i++) {
          item_sum_t a = A[i];
          b = buscar_combinacion_optima(B_filtrada, W - a.second);
          if (b.second + a.second <= W) {
               b.second += a.second;
               b.first += a.first;
          } else if (b.first > a.first) {
               a = b;
          }

          if (optima.first < a.first) 
               optima = a;
     }
     return optima;
}

item_sum_t
buscar_combinacion_optima(vector<item_sum_t> &B_ordenada, int tope)
{
     unsigned long desde = 0;
     unsigned long hasta = B_ordenada.size() - 1;
     unsigned med;

     if (B_ordenada[B_ordenada.size()-1].second <= tope) {
          B_ordenada[B_ordenada.size()-1];
     }

     while (desde < hasta) {
          med = (desde + hasta) / 2;
          if (B_ordenada[med].second == tope)
               return B_ordenada[med];
          if (tope < B_ordenada[med].second) {
               hasta = med;
          } else  {
               desde = med;  
          }
     }

     // if (B_ordenada.size() == 1)
     //      return B_ordenada[0];
     // unsigned long desde = 0;
     // unsigned long hasta = B_ordenada.size();
     // unsigned med;
     // while (desde < hasta) {
     //      med = (desde + hasta) / 2;
     //      if (B_ordenada[med].second >= tope) {
     //           hasta = med;
     //      } else  {
     //           desde = med;  
     //      }
     // }
     // if (desde > hasta) {
     //      cout << "not found!!!!!!!!\n";
     //      abort();
     // }
          
     // if ( med >= B_ordenada.size()) {
     //      cerr << "@@@@@@@@@@@@@@@@@q  errror!\n";
     //      cout << "med: " << med << "\tlen: "<< B_ordenada.size()<< endl;
     //      abort();
     // }
     // return B_ordenada[med];
}
