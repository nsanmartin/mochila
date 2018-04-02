//#include <vector>
// #include <chrono>
// #include <iostream>
// #include <numeric>
// #include <random>
// #include <chrono>

#include "mochila.h"
#include <iostream>
using namespace std;


int main (int argc, char ** argv) {
     int n = 4  ;
     int W = 11;
     //vector<item_t> items = random_items(n, 5);
     vector<item_t> items;
     items.push_back (make_pair(1,1));
     items.push_back (make_pair(6,2));
     items.push_back (make_pair(18,5));
     items.push_back (make_pair(22,6));
     items.push_back (make_pair(28,7));
                           //items.push_back (make_pair(
                                        
     for (auto x : items) { cout << x.first << "/" << x.second << endl;}
     cout << "n: " <<  n << "\tW: " << W << endl;
     int din = dinamica(items, W);
     cout << "din:\t";
     cout << din << endl;
     cout << "mm:\t";
     cout << meet_middle(items, W) <<  endl;
     cout << "bt:\t";
     cout << backtracking2(items, W) << endl;
     cout << "fb:\t";
     cout << fuerza_bruta4(items, W) << endl;
}
