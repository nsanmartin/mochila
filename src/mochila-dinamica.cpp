#include <iostream>
#include <numeric>
#include <algorithm>
#include <array>
#include <assert.h>

#include "mochila.h"
using namespace std;

inline bool mul_overflow(int x, int y) {                        
     return x != 0 && ((y * x) / x) != y;
}

class Tabla {
     int _nfilas;
     int _ncolumnas;
     vector<int> _tabla;
public:
     Tabla(int nfilas, int ncols) {
          assert(!mul_overflow(nfilas, ncols));
          _tabla = vector<int>(nfilas * ncols);
          _nfilas = nfilas;
          _ncolumnas = ncols;
     }
     int get(int fila, int col) {
          return _tabla[fila * _ncolumnas + col];
     }
     void set(int fila, int col, int elem) {
          _tabla[fila * _ncolumnas + col] = elem;
     }
};

int dinamica (vector<item_t> &items, int W) {
     const int n = items.size();
     if (n == 0)
          return 0;
     Tabla tabla(n + 1, W + 1);
     int k = 1;

     for (int i = 0; i < n + 1; i ++)
          for (int j = 0; j < W + 1; j++) {
               int valor;
               if (i == 0 || j == 0) valor = 0;
               else {
                    int w_i = items[i-1].second;
                    int v_i = items[i-1].first;
                    valor = tabla.get (i - 1, j);
                    if (j >= w_i) {
                         int valor2 =
                              tabla.get (i-1, j - w_i) + v_i;
                         if (valor2 > valor)
                              valor = valor2;
                    }
               }
               tabla.set(i,j,valor);
          }

     return tabla.get(n, W);
}
