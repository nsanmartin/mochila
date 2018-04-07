#include <vector>
#include <chrono>
#include <iostream>
#include <algorithm>
#include "mochila.h"


/* #include <numeric> */
/* #include <random> */

using namespace std;

void comparar_bt_mm(int W, vector<item_t> items) ;

void muestrear_algoritmos(int W, vector<item_t> items) {
     auto start_fb4 = chrono::steady_clock::now();
     int res4 = fuerza_bruta(items, W);
     auto end_fb4 = chrono::steady_clock::now();
     auto diff_fb4 = end_fb4 - start_fb4;
     cout << chrono::duration <double, milli> (diff_fb4).count() << " ";
     
     auto start_bt2 = chrono::steady_clock::now();
     int resbt2 = backtracking (items, W);
     auto end_bt2 = chrono::steady_clock::now();
     auto diff_bt2 = end_bt2 - start_bt2;
     cout << chrono::duration <double, milli> (diff_bt2).count() << " ";

     auto start_mm = chrono::steady_clock::now();
     int resmm = meet_middle (items, W);
     auto end_mm = chrono::steady_clock::now();
     auto diff_mm = end_mm - start_mm;
     cout << chrono::duration <double, milli> (diff_mm).count() << " ";
     
     auto start_din = chrono::steady_clock::now();
     int resdin = dinamica(items, W);
     auto end_din = chrono::steady_clock::now();
     auto diff_din = end_din - start_din;
     cout << chrono::duration <double, milli> (diff_din).count() << " ";
     
     if (resbt2 != res4 || resbt2 != resmm || resbt2 != resdin) {
          cerr << "Error!!! fb4 , meet y bt no coincieden!!!!" << endl;
          cerr << "resfb: " << res4 << "\t resmm: " << resmm
               << "\t resbt2: " << resbt2 << "\t resdin: "
               << resdin
               << endl;
          for (auto x : items)
               cout << x.first << "/" << x.second << " "<<  endl ;
          exit(1);
     } else {
          //cout << res4 << endl;
     }

}

void muestrear_algoritmos_bt_mm_din(int W, vector<item_t> items) {
     cout << "__ ";

     auto start_bt2 = chrono::steady_clock::now();
     int resbt2 = backtracking (items, W);
     auto end_bt2 = chrono::steady_clock::now();
     auto diff_bt2 = end_bt2 - start_bt2;
     cout << chrono::duration <double, milli> (diff_bt2).count() << " ";

     auto start_mm = chrono::steady_clock::now();
     int resmm = meet_middle (items, W);
     auto end_mm = chrono::steady_clock::now();
     auto diff_mm = end_mm - start_mm;
     cout << chrono::duration <double, milli> (diff_mm).count() << " ";
     
     auto start_din = chrono::steady_clock::now();
     int resdin = dinamica(items, W);
     auto end_din = chrono::steady_clock::now();
     auto diff_din = end_din - start_din;
     cout << chrono::duration <double, milli> (diff_din).count() << " ";
     cout << endl;
     if ( resbt2 != resmm || resbt2 != resdin) {
          cerr << "Error!!! fb4 , meet y bt no coincieden!!!!" << endl;
          cerr << "\t resmm: " << resmm
               << "\t resbt: " << resbt2 << "\t resdin: "
               << resdin
               << endl;
          for (auto x : items)
               cout << x.first << "/" << x.second << " "<<  endl ;
          exit(1);
     } else {
          //cout << res4 << endl;
     }

}



void muestrear_algoritmos_bt_din(int W, vector<item_t> items) {
     cout << "__ ";

     auto start_bt2 = chrono::steady_clock::now();
     int resbt2 = backtracking (items, W);
     auto end_bt2 = chrono::steady_clock::now();
     auto diff_bt2 = end_bt2 - start_bt2;
     cout << chrono::duration <double, milli> (diff_bt2).count() << " ";

     cout << " __ ";
     
     auto start_din = chrono::steady_clock::now();
     int resdin = dinamica(items, W);
     auto end_din = chrono::steady_clock::now();
     auto diff_din = end_din - start_din;
     cout << chrono::duration <double, milli> (diff_din).count() << " ";
     cout << endl;
     if (  resbt2 != resdin) {
          cerr << "Error!!! fb4 , meet y bt no coincieden!!!!" << endl;
          cerr << "\t resbt: " << resbt2 << "\t resdin: "
               << resdin
               << endl;
          for (auto x : items)
               cout << x.first << "/" << x.second << " "<<  endl ;
          exit(1);
     } else {
          //cout << res4 << endl;
     }

}


void test_cons(int n, int W) {
     vector<item_t> items = random_items(n);
     muestrear_algoritmos(W, items);
     
}


void muestrear_din(int W, vector<item_t> items) {
     auto start_din = chrono::steady_clock::now();
     int resdin = dinamica(items, W);
     auto end_din = chrono::steady_clock::now();
     auto diff_din = end_din - start_din;
     cout << chrono::duration <double, milli> (diff_din).count() << " ";
     cout << endl;
 }
