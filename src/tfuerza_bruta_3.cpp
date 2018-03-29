//#include <vector>
#include <chrono>
#include <iostream>
#include <numeric>
#include <random>
#include <chrono>

#include "mochila.h"

using namespace std;
void tfuerza_bruta_3(int n, int W);
void tfuerza_bruta_3_cmp(int W) ;
void tfuerza_bruta_3_cmp_rand(int n, int W) ;
void tfuerza_bruta_err() ;

int main (int argc, char ** argv) {
     int n = 2;
     int W = 100;

     
     if (argc == 1) {
          
          tfuerza_bruta_err();
     }

     for (int i = 1; i < argc; i++) {
          n = atoi(argv[i]);
          tfuerza_bruta_3_cmp_rand(n, W);
     }
}


void tfuerza_bruta_3(int n, int W) {
     cout << "steady_clock" << endl;
     cout << chrono::steady_clock::period::num << endl;
     cout << chrono::steady_clock::period::den << endl;
     cout << "steady = " << boolalpha << chrono::steady_clock::is_steady
          << endl << endl;

     vector<int> ps;
     vector<int> ws;
     vector<item_t> items = random_items(n);
     copiar_items(items, ps, ws);

     auto start_mm = chrono::steady_clock::now();
     int resmm = fuerza_bruta3 (items, W);
     auto end_mm = chrono::steady_clock::now();
     auto diff_mm = end_mm - start_mm;
     cout << "Tiempo utilizado por meet in the middle: "
          << chrono::duration <double, nano> (diff_mm).count() << " ns"
          << "\tn: " << n <<endl;

}


void tfuerza_bruta_3_cmp(int W) {

     vector<item_t> items;
     items.push_back(make_pair(18,77));

     int resfb2 = fuerza_bruta2 (items, W);
     int resfb3 = fuerza_bruta3 (items, W);
     int resmm = meet_middle(items, W);

     if (resfb3 != resfb2 || resfb3 != resmm) {
          cout << "error!!\n";
          print_items(items);
     }
     
     
}

void tfuerza_bruta_3_cmp_rand(int n, int W) {

     vector<item_t> items = random_items(n);

     int resfb2 = fuerza_bruta2 (items, W);
     int resfb3 = fuerza_bruta3 (items, W);
     int resmm = meet_middle(items, W);

     if (resfb3 != resfb2 || resfb3 != resmm) {
          cout << "error!!\n";
          cout << "fb2:\t" << resfb2 << endl
               << "mm:\t" << resmm << endl
               << "fb3:\t" << resfb3 << endl;
          print_items(items);
          abort();
     } else {
          cout << resfb2 << endl;
     }
     
     
}


void tfuerza_bruta_err() {

     vector<item_t> items;

     // items.push_back(make_pair(2,45));
     // items.push_back(make_pair(35,64));
     // items.push_back(make_pair(86,94));
     // items.push_back(make_pair(84,59));
     
     items.push_back(make_pair(18,96));
     items.push_back(make_pair(72,5));



     int resfb3 = fuerza_bruta3 (items, 100);

     cout << resfb3 << endl;

     
     
}
