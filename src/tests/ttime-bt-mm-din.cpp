#include <iostream>
#include <numeric>
#include <chrono>

#include "../mochila.h"

using namespace std;

void muestrear_algoritmos_bt_mm_din(int W, vector<item_t> items) ;

void test_cons_bt_mm_din(int n, int W) {
     vector<item_t> items = random_items(n);
     muestrear_algoritmos_bt_mm_din(W, items);
}


int main (int argc, char ** argv) {

     int n;
     int W = rand_int_mod(1000) ;
     if (argc == 2) {
          n = atoi(argv[1]);
          cout << W << " " << n << " ";
          test_cons_bt_mm_din(n, W);
     } else if (argc == 3){
          W = atoi(argv[1]);
          n = atoi(argv[2]);
          cout << n << " " << W << " " ;
          test_cons_bt_mm_din(n, W);
          cout << endl;
     } else {
          cout << "uso: " << argv[0] << " W n.\n";
     }
}
