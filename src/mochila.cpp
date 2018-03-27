#include <iostream>
#include <numeric>
#include <random>

#include "mochila.h"

using namespace std;

void test1(int n, int W) ;

int main (int argc, char ** argv) {

     int n = 14;
     int W = 100;

     if (argc > 1)
          n = atoi(argv[1]);
     test0(n, W);
}

void test0(int n, int W) {

     vector<int> ps;
     vector<int> ws;
     vector<item_t> items = random_items(n);
     copiar_items(items, ps, ws);
     int res = fuerza_bruta(ps, ws, W);
     

     int res2 = fuerza_bruta2(items, W);

     if (res != res2) {
          cerr << "Error!!! fb y fb2 no coincieden!";
          cerr << "res: " << res << " res2: " << res2;
          exit(1);
     } else {
          cout << res2 << " ";
     }
     cout << endl;
     int resmm = meet_middle (items, W) ;
     cout << "meet middle: " << resmm;
}
void test1(int n, int W) {
     vector<item_t> items;
     items.push_back(make_pair(1, 4));
     items.push_back(make_pair(2, 4));
     items.push_back(make_pair(3,7));
     items.push_back(make_pair(5,7));
     int res2 = fuerza_bruta2(items, W);
     int resmm = meet_middle (items, W);
     cout << "res2:\t " << res2 << endl;
     cout << "resmm:\t" << resmm << endl;
}


vector<int> random_int_vector(int size) {
     default_random_engine generator;
     generator.seed(random_device()());
     uniform_int_distribution<int>
          distribution(1, 100);
     //auto cubilete = bind ( distribution, generator );
     vector<int> data;
     for (int i = 0; i < size; i++) {
          data.push_back(distribution(generator));
     }
     return data;
}


void copiar_items(vector<item_t> &items,
                  vector<int> &ps, vector<int> &ws) {
     for (item_t x : items) {
          ps.push_back(x.first);
          ws.push_back(x.second);
     }

}



vector<item_t> random_items(int cantidad) {
     default_random_engine generator;
     generator.seed(random_device()());
     uniform_int_distribution<int>
          distribution(1, 100);
     //auto cubilete = bind ( distribution, generator );
     vector<item_t> data;
     for (int i = 0; i < cantidad; i++) {
          data.push_back(make_pair(distribution(generator),
                                   distribution(generator)));
     }
     return data;
}
