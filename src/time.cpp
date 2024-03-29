#include <vector>
#include <chrono>
#include <iostream>
#include <algorithm>
#include "mochila.h"


/* #include <numeric> */
/* #include <random> */

using namespace std;

int muestrear_fb(int W, vector<item_t> items) {
     auto start_fb = chrono::steady_clock::now();
     int resfb = fuerza_bruta(items, W);
     auto end_fb = chrono::steady_clock::now();
     auto diff_fb = end_fb - start_fb;
     cout << chrono::duration <double, milli> (diff_fb).count() << " ";
     return resfb;
}
int muestrear_din(int W, vector<item_t> items) {
     auto start_din = chrono::steady_clock::now();
     int resdin = dinamica(items, W);
     auto end_din = chrono::steady_clock::now();
     auto diff_din = end_din - start_din;
     cout << chrono::duration <double, milli> (diff_din).count() << " ";
     return resdin;
 }

int muestrear_bt(int W, vector<item_t> items) {
     auto start_bt = chrono::steady_clock::now();
     int resbt = backtracking(items, W);
     auto end_bt = chrono::steady_clock::now();
     auto diff_bt = end_bt - start_bt;
     cout << chrono::duration <double, milli> (diff_bt).count() << " ";
     return resbt;
 }

int muestrear_bt0(int W, vector<item_t> items) {
     auto start_bt = chrono::steady_clock::now();
     int resbt = backtracking0(items, W);
     auto end_bt = chrono::steady_clock::now();
     auto diff_bt = end_bt - start_bt;
     cout << chrono::duration <double, milli> (diff_bt).count() << " ";
     return resbt;
 }

int muestrear_mm(int W, vector<item_t> items) {
     auto start_mm = chrono::steady_clock::now();
     int resmm = meet_middle(items, W);
     auto end_mm = chrono::steady_clock::now();
     auto diff_mm = end_mm - start_mm;
     cout << chrono::duration <double, milli> (diff_mm).count() << " ";
     return resmm;
 }

void muestrear_algoritmos(int W, vector<item_t> items) {
     int resfb = muestrear_fb(W, items);
     int resbt = muestrear_bt(W, items);
     int resmm = muestrear_mm(W, items);
     int resdin = muestrear_din(W, items);
     
     if (resfb != resbt || resbt != resmm || resmm != resdin) {
          cerr << "Error: las soluciones no coinciden." << endl;
          cerr << "resfb: " << resfb << "\t resmm: " << resmm
               << "\t resbt: " << resbt << "\t resdin: " << resdin
               << endl;
          for (auto x : items)
               cout << x.first << "/" << x.second << " "<<  endl ;
          exit(1);
     } 
}

void muestrear_algoritmos_bt_mm_din(int W, vector<item_t> items) {

     int resbt = muestrear_bt(W, items);
     int resmm = muestrear_mm(W, items);
     int resdin = muestrear_din(W, items);
     cout << "__ ";

     if ( resbt != resmm || resbt != resdin) {
          cerr << "Error: fb , meet y bt no coincieden." << endl;
          cerr << "\t resmm: " << resmm
               << "\t resbt: " << resbt << "\t resdin: "
               << resdin
               << endl;
          for (auto x : items)
               cout << x.first << "/" << x.second << " "<<  endl ;
          exit(1);
     } 
}


void muestrear_algoritmos_bt0_bt(int W, vector<item_t> items) {
     int resbt0 = muestrear_bt0(W, items);
     int resbt = muestrear_bt(W, items);
     if ( resbt0 != resbt) {
          cerr << "Error: bt0 , y bt no coincieden." << endl;
          cerr << "\t resbt: " << resbt0
               << "\t resbt2: " << resbt 
               << endl;
          cout << "========\n";
          cout << items.size() << " " << W << endl;
          for (auto x : items)
               cout << x.second << " " << x.first << " "<<  endl ;
          exit(1);
     } 
}



// void muestrear_algoritmos_bt_din(int W, vector<item_t> items) {
//      int resbt = muestrear_bt(W, items);
//      int resdin = muestrear_din(W, items);
//      if ( resbt != resdin) {
//           cerr << "Error: bt , y bt2 no coincieden." << endl;
//           cerr << "\t resbt: " << resbt
//                << "\t resdin: " << resdin 
//                << endl;
//           cout << "========\n";
//           cout << items.size() << " " << W << endl;
//           for (auto x : items)
//                cout << x.second << " " << x.first << " "<<  endl ;
//           exit(1);
//      } 

// }

void muestrear_algoritmos_bt_din(int W, vector<item_t> items) {
     int rbt = muestrear_bt(W, items);
     int rdin = muestrear_din(W, items);
     if (  rbt != rdin) {
          cerr << "Error!!! fb4 , meet y bt no coincieden!!!!" << endl;
          cerr << "\t resbt: " << rbt << "\t resdin: "
               << rdin
               << endl;
          for (auto x : items)
               cout << x.first << "/" << x.second << " "<<  endl ;

          cout << "W: " << W << endl;
          exit(1);
     } 
}
