#include <iostream>
#include <numeric>
#include <chrono>

#include "mochila.h"

using namespace std;
void time0(int n, int W) ;
void time1(int n, int W) ;
void time2(int n, int W) ;


int main (int argc, char ** argv) {
     cout << "steady_clock "
          << chrono::steady_clock::period::num 
          << chrono::steady_clock::period::den 
          << "steady = " << boolalpha
          << chrono::steady_clock::is_steady << endl << endl;

     int n;
     int W = rand_int_mod(1000) ;
     if (argc == 2) {
          n = atoi(argv[1]);
          cout << "W: " << W << "\t n: " << n << endl;
          time2(n, W);
     } else if (argc == 3){
          W = atoi(argv[1]);
          n = atoi(argv[2]);
          cout << "W: " << W << "\t n: " << n << endl;
          time2(n, W);

     } else {
          cout << "falta param.\n";
     }
}
