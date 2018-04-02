#include <random>
#include <iostream>
#include "mochila.h"
#include <string>
#include <fstream>
using namespace std;

int rand_int_mod(int n) {
     default_random_engine generator;
     generator.seed(random_device()());
     uniform_int_distribution<int>
          distribution(1, n);

     return distribution(generator);
     
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
