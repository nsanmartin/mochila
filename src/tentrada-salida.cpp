#include <iostream>
#include <numeric>
#include <chrono>

#include "mochila.h"

using namespace std;

int main(int argc, char** argv) {
     int W;
     vector<item_t> items;
     if (argc == 1) {
          cerr << "falta nombre de archivo\n";
          exit(1);
     }
     string filename = argv[1];

     leer_parametros(W, items, filename);
     for (item_t x : items) {
          cout << x.first << "/" << x.second << endl;
     }

     comparar_algotirmos(W, items);
}
