//#include <vector>
#include <chrono>
#include <iostream>
#include <numeric>
#include <random>
#include <chrono>

#include "mochila.h"

using namespace std;
// void tfuerza_bruta_3(int n, int W);
// void tfuerza_bruta_3_cmp(int W) ;
// void tfuerza_bruta_3_cmp_rand(int n, int W) ;
// void tfuerza_bruta_err() ;
void tfuerza_bruta_4_cmp_rand(int n, int W) ;

int main (int argc, char ** argv) {
     int n = 2;
     int W = 100;

     
     if (argc == 1) {
          cout << "falta param\n";
          exit(0);
     }

     for (int i = 1; i < argc; i++) {
          n = atoi(argv[i]);
          tfuerza_bruta_4_cmp_rand(n, W);
     }
}


void tfuerza_bruta_4_cmp_rand(int n, int W) {

     vector<item_t> items = random_items(n);

     int resfb2 = fuerza_bruta2 (items, W);
     int resfb4 = fuerza_bruta4 (items, W);
     int resmm = meet_middle(items, W);

     if (resfb4 != resfb2 || resfb4 != resmm) {
          cout << "error!!\n";
          cout << "fb2:\t" << resfb2 << endl
               << "mm:\t" << resmm << endl
               << "fb3:\t" << resfb4 << endl;
          print_items(items);
          abort();
     } else {
          cout << resfb2 << endl;
     }
     
     
}


// void tfuerza_bruta_err() {

//      vector<item_t> items;

//      // items.push_back(make_pair(2,45));
//      // items.push_back(make_pair(35,64));
//      // items.push_back(make_pair(86,94));
//      // items.push_back(make_pair(84,59));
     
//      items.push_back(make_pair(18,96));
//      items.push_back(make_pair(72,5));



//      int resfb3 = fuerza_bruta3 (items, 100);

//      cout << resfb3 << endl;

     
     
// }
