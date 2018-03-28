//#include <vector>
#include <chrono>
#include <iostream>
#include <numeric>
#include <random>
#include <chrono>

#include "mochila.h"

using namespace std;
void tmeet_in_the_middle(int n, int W);


int main (int argc, char ** argv) {
     if (argc == 1) {
          cout << "Flata parametro n\n"; exit(0);
     }
     cout << "steady_clock" << endl;
     cout << chrono::steady_clock::period::num << endl;
     cout << chrono::steady_clock::period::den << endl;
     cout << "steady = " << boolalpha << chrono::steady_clock::is_steady
          << endl << endl;

     int n = 2;
     int W = 100;
     for (int i = 1; i < argc; i++) {
          n = atoi(argv[i]);
          tmeet_in_the_middle(n, W);
     }
}


void tmeet_in_the_middle(int n, int W) {

     vector<int> ps;
     vector<int> ws;
     vector<item_t> items = random_items(n);
     copiar_items(items, ps, ws);

     auto start_mm = chrono::steady_clock::now();
     int resmm = meet_middle (items, W);
     auto end_mm = chrono::steady_clock::now();
     auto diff_mm = end_mm - start_mm;
     cout << "Tiempo utilizado por meet in the middle: "
          << chrono::duration <double, nano> (diff_mm).count() << " ns"
          << "\tn: " << n <<endl;

}


