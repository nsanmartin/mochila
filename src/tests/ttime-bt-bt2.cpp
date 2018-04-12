#include <iostream>
#include <numeric>
#include <chrono>

#include "../mochila.h"

using namespace std;

void muestrear_algoritmos_bt_bt2(int W, vector<item_t> items) ;


int main (int argc, char ** argv) {
     int W;
     vector<item_t> items;
     if (argc == 1) {
          leer_parametros_stream(W, items, cin);
     } else {
          string filename = argv[1];
          ifstream file;
          file.open(filename);
          if (!file) {
               cerr << "No se pudo leer " << filename << endl;
               exit(1);
          }

          leer_parametros_stream(W, items, file);
     }
     cout << items.size() << " " << W << " ";
     muestrear_algoritmos_bt_bt2(W, items);
     cout << endl;
}