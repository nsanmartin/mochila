#include <iostream>
#include <numeric>
#include <algorithm>

#include "mochila.h"
using namespace std;


void
resolver_fuerza_bruta (vector<item_t> &items, int i, int W, mochila &m,
                       int &menor_beneficio_sacado);

int fuerza_bruta (vector<item_t> &items, int W) {
     mochila m;
     m.afuera = item_t(0,0);
     m.adentro = item_t(0,0);
     int menor_beneficio_sacado, beneficio_total = 0;

     for (int i = 0; i < items.size(); i ++) 
          beneficio_total += items[i].first;
     menor_beneficio_sacado = beneficio_total;
     resolver_fuerza_bruta(items, items.size(), W, m, menor_beneficio_sacado);

     return beneficio_total - menor_beneficio_sacado;
}


void
resolver_fuerza_bruta (vector<item_t> &items, int i, int W, mochila &m,
                       int &menor_beneficio_sacado)
{
     if (i == 0) {// ultimo
          if (m.afuera.first < menor_beneficio_sacado &&
              m.adentro.second <= W)
               menor_beneficio_sacado  = m.afuera.first;
     } else {
          mochila m_sin_iesimo(m);
          agregar_item_a_suma(m.adentro, items[i - 1]);
          resolver_fuerza_bruta(items, i - 1, W, m,
                                menor_beneficio_sacado);
          agregar_item_a_suma(m_sin_iesimo.afuera, items[i - 1]);
          resolver_fuerza_bruta(items, i - 1, W, m_sin_iesimo,
                                menor_beneficio_sacado);
     }
}




