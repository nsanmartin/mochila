#include <iostream>
#include <numeric>
#include <chrono>

#include "mochila.h"

using namespace std;
void time0(int n, int W) ;
void time1(int n, int W) ;


int main (int argc, char ** argv) {
     cout << "steady_clock "
          << chrono::steady_clock::period::num 
          << chrono::steady_clock::period::den 
          << "steady = " << boolalpha
          << chrono::steady_clock::is_steady << endl << endl;

     int n = 2;
     int W = 100;
     if (argc > 1) {
          n = atoi(argv[1]);
          time1(n, W);
     } else {
          cout << "falta param.\n";
     }
}
