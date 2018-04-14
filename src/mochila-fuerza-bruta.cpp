#include <iostream>
#include <numeric>
#include <algorithm>

#include "mochila.h"
using namespace std;


void
resolver_fuerza_bruta (vector<item_t> &items, int i, int W,item_t &m,
                       int &solucion);

int fuerza_bruta (vector<item_t> &items, int W) {
     item_t m = item_t(0,0);
     int solucion = 0;
     resolver_fuerza_bruta(items, items.size(), W, m, solucion);
     return solucion;
}

void
resolver_fuerza_bruta (vector<item_t> &items, int i, int W, item_t &m,
                       int &solucion)
{
     if (i > 0) {
          item_t m_sin_iesimo(m);
          agregar_item_a_suma(m, items[i - 1]);
          resolver_fuerza_bruta(items, i - 1, W, m, solucion);
          resolver_fuerza_bruta(items, i - 1, W, m_sin_iesimo, solucion);
     } else if (m.first > solucion && m.second <= W) {
               solucion  = m.first;
     }

}




