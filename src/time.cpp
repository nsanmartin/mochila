#include <vector>
#include <chrono>
#include <iostream>
#include <algorithm>
#include "mochila.h"


/* #include <numeric> */
/* #include <random> */

using namespace std;

void comparar_bt_mm(int W, vector<item_t> items) ;

void time0(int n, int W) {

     vector<int> ps;
     vector<int> ws;
     vector<item_t> items = random_items(n);
     copiar_items(items, ps, ws);

     auto start_fb = chrono::steady_clock::now();
     int res = fuerza_bruta(ps, ws, W);
     auto end_fb = chrono::steady_clock::now();
     auto diff_fb = end_fb - start_fb;
     cout << "Tiempo utilizado por fb:\t "
          << chrono::duration <double, nano> (diff_fb).count() << " ns"
          << endl;

     auto start_fb2 = chrono::steady_clock::now();
     int res2 = fuerza_bruta2(items, W);
     auto end_fb2 = chrono::steady_clock::now();
     auto diff_fb2 = end_fb2 - start_fb2;
     cout << "Tiempo utilizado por fb2:\t "
          << chrono::duration <double, nano> (diff_fb2).count() << " ns"
          << endl;


     auto start_fb4 = chrono::steady_clock::now();
     int res4 = fuerza_bruta4(items, W);
     auto end_fb4 = chrono::steady_clock::now();
     auto diff_fb4 = end_fb4 - start_fb4;
     cout << "Tiempo utilizado por fb4:\t "
          << chrono::duration <double, nano> (diff_fb4).count() << " ns"
          << endl;

     auto start_mm = chrono::steady_clock::now();
     int resmm = meet_middle (items, W);
     auto end_mm = chrono::steady_clock::now();
     auto diff_mm = end_mm - start_mm;
     cout << "Tiempo utilizado por mm:\t "
          << chrono::duration <double, nano> (diff_mm).count() << " ns"
          << endl;




     if (res != res2) {
          cerr << "Error!!! fb y fb2 no coincieden!!!!";
          cerr << "res: " << res << " res2: " << res2 << endl;
          exit(1);
     }
               
     if (res != resmm) {
         cerr << "Error!!! fb y meet no coincieden!!!!";
         cerr << "res: " << res << " resmm: " << resmm << endl;
         for (auto x : items)
              cout << x.first << "/" << x.second << " "<<  endl ;
         exit(1);
     }
                    
     if (res4 != resmm) {
         cerr << "Error!!! fb4 y meet no coincieden!!!!";
         cerr << "res: " << res << " resmm: " << resmm << endl;
         for (auto x : items)
              cout << x.first << "/" << x.second << " "<<  endl ;
         exit(1);
     } 


          cout << resmm << " " << endl;
}

void time2(int n, int W) {
     
     vector<item_t> items = random_items(n);
     comparar_bt_mm(W, items);

}
void time1(int n, int W) {

     vector<item_t> items = random_items(n);
     // sort(items.begin(), items.end(),
     //      [](item_t x, item_t y) {
     //           return  x.first > y.first;
     //           //return x.first / x.second > y.first / y.second;
     //      });
     for (int i = 0; i < items.size(); i++) {
          cout << items[i].first << "/" << items[i].second << " ";
     }
     cout << endl;


     auto start_mm = chrono::steady_clock::now();
     int resmm = meet_middle (items, W);
     auto end_mm = chrono::steady_clock::now();
     auto diff_mm = end_mm - start_mm;
     cout << "Tiempo utilizado por mm:\t "
          << chrono::duration <double, milli> (diff_mm).count() << " ms"
          << endl;

     
     auto start_bt = chrono::steady_clock::now();
     int resbt = backtracking (items, W);
     auto end_bt = chrono::steady_clock::now();
     auto diff_bt = end_bt - start_bt;
     cout << "Tiempo utilizado por bt:\t "
          << chrono::duration <double, milli> (diff_bt).count() << " ms"
          << endl;

     auto start_bt2 = chrono::steady_clock::now();
     int resbt2 = backtracking2 (items, W);
     auto end_bt2 = chrono::steady_clock::now();
     auto diff_bt2 = end_bt2 - start_bt2;
     cout << "Tiempo utilizado por bt2:\t "
          << chrono::duration <double, milli> (diff_bt2).count() << " ms"
          << endl;

     auto start_fb4 = chrono::steady_clock::now();
     int res4 = fuerza_bruta4(items, W);
     auto end_fb4 = chrono::steady_clock::now();
     auto diff_fb4 = end_fb4 - start_fb4;
     cout << "Tiempo utilizado por fb4:\t "
          << chrono::duration <double, milli> (diff_fb4).count() << " ms"
          << endl;

     
     
                    
     if (resbt != res4 || resbt != resmm || resbt != resbt2) {
          cerr << "Error!!! fb4 , meet y bt no coincieden!!!!" << endl;
          cerr << "resfb: " << res4 << "\t resmm: " << resmm
               << "\t resbt: " << resbt << "\t resbt2: " << resbt2
               << endl;
          for (auto x : items)
               cout << x.first << "/" << x.second << " "<<  endl ;
          exit(1);
     } 

     
     cout << resmm << " " << endl;
}


void comparar_algotirmos(int W, vector<item_t> items) {

     auto start_mm = chrono::steady_clock::now();
     int resmm = meet_middle (items, W);
     auto end_mm = chrono::steady_clock::now();
     auto diff_mm = end_mm - start_mm;
     cout << "Tiempo utilizado por meet middle:\t "
          << chrono::duration <double, milli> (diff_mm).count() << " ms"
          << endl;
     
     auto start_bt2 = chrono::steady_clock::now();
     int resbt2 = backtracking2 (items, W);
     auto end_bt2 = chrono::steady_clock::now();
     auto diff_bt2 = end_bt2 - start_bt2;
     cout << "Tiempo utilizado por backtrakingt2:\t "
          << chrono::duration <double, milli> (diff_bt2).count() << " ms"
          << endl;

     auto start_fb4 = chrono::steady_clock::now();
     int res4 = fuerza_bruta4(items, W);
     auto end_fb4 = chrono::steady_clock::now();
     auto diff_fb4 = end_fb4 - start_fb4;
     cout << "Tiempo utilizado por fuerza brutab4:\t "
          << chrono::duration <double, milli> (diff_fb4).count() << " ms"
          << endl;

     
     auto start_din = chrono::steady_clock::now();
     int resdin = dinamica(items, W);
     auto end_din = chrono::steady_clock::now();
     auto diff_din = end_din - start_din;
     cout << "Tiempo utilizado por dinamica:\t\t "
          << chrono::duration <double, milli> (diff_din).count() << " ms"
          << endl;


     
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
          cout << res4 << endl;
     }

}

void muestrear_algoritmos(int W, vector<item_t> items) {
     auto start_fb4 = chrono::steady_clock::now();
     int res4 = fuerza_bruta4(items, W);
     auto end_fb4 = chrono::steady_clock::now();
     auto diff_fb4 = end_fb4 - start_fb4;
     cout << chrono::duration <double, milli> (diff_fb4).count() << " ";
     
     auto start_bt2 = chrono::steady_clock::now();
     int resbt2 = backtracking2 (items, W);
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

void comparar_bt_mm(int W, vector<item_t> items) {

     auto start_mm = chrono::steady_clock::now();
     int resmm = meet_middle (items, W);
     auto end_mm = chrono::steady_clock::now();
     auto diff_mm = end_mm - start_mm;
     cout << "Tiempo utilizado por meet middle:\t "
          << chrono::duration <double, milli> (diff_mm).count() << " ms"
          << endl;
     
     auto start_bt2 = chrono::steady_clock::now();
     int resbt2 = backtracking2 (items, W);
     auto end_bt2 = chrono::steady_clock::now();
     auto diff_bt2 = end_bt2 - start_bt2;
     cout << "Tiempo utilizado por backtrakingt2:\t "
          << chrono::duration <double, milli> (diff_bt2).count() << " ms"
          << endl;
                    
     if (resbt2 != resmm) {
          cerr << "Error!!!  meet y bt no coincieden!!!!" << endl;
          cerr  << "\t resmm: " << resmm
               << "\t resbt2: " << resbt2
               << endl;
          for (auto x : items)
               cout << x.first << "/" << x.second << " "<<  endl ;
          exit(1);
     } else {
          cout << resbt2 << endl;
     }

}
