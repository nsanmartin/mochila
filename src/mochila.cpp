#include <iostream>
#include <numeric>
#include <chrono>

#include "mochila.h"

using namespace std;


int main (int argc, char ** argv) {
     cout << "steady_clock" << endl;
     cout << chrono::steady_clock::period::num << endl;
     cout << chrono::steady_clock::period::den << endl;
     cout << "steady = " << boolalpha << chrono::steady_clock::is_steady << endl << endl;

     int n = 2;
     int W = 100;
     if (argc > 1) {
          n = atoi(argv[1]);
          test0(n, W);
     } else {
          test1(n, W);
          test2(n, W);
          test3(n, W);
          test4(n, W);
          test5(n, W);
     }
}
