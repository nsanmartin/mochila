//#include <vector>
#include <chrono>
#include <iostream>
#include <numeric>
#include <random>
#include <chrono>

#include "mochila.h"

using namespace std;

void tbacktracking_cmp_rand(int n, int W) ;
void tbacktracking_err() ;

int main (int argc, char ** argv) {
     int n = 2;
     int W = rand_int_mod(1000);
     cout << "W: " << W << " " ;
     
     if (argc == 1) {
          tbacktracking_err() ;
          exit(0);
     }

     for (int i = 1; i < argc; i++) {
          n = atoi(argv[i]);
          cout << "n: " << n;
          tbacktracking_cmp_rand(n, W);
     }
}


void tbacktracking_cmp_rand(int n, int W) {

     vector<item_t> items = random_items(n);

     int resfb4 = fuerza_bruta4 (items, W);
     int resmm = meet_middle(items, W);
     int resbt = backtracking(items, W);
     int resbt2 = backtracking2(items, W);
          
     if (resbt != resfb4 || resbt != resmm || resbt != resbt2) {
          cout <<  "tbacktracking_cmp_rand ";
          cout << "error!!\n";
          cout << "fb4:\t" << resfb4 << endl
               << "mm:\t" << resmm << endl
               << "bt:\t" << resbt << endl
               << "bt2:\t" << resbt2 << endl;
          print_items(items);
          abort();
     } else {
          cout << " res: " << resbt << endl;
     }
     
     
}

void tbacktracking_err() {

     vector<item_t> items;

     items.push_back(make_pair(86,94));
     items.push_back(make_pair(30,33));
     items.push_back(make_pair(97,84));
     // items.push_back(make_pair(84,59));
     // items.push_back(make_pair(18,96));
     // items.push_back(make_pair(72,5));



     int res = backtracking (items, 100);

     cout << res << endl;

     
     
}
