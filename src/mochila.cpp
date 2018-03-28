#include <iostream>
#include <numeric>
#include <random>

#include "mochila.h"

using namespace std;


int main (int argc, char ** argv) {

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
