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

void copiar_items(vector<item_t> &items,
                  vector<int> &ps, vector<int> &ws) {
     for (item_t x : items) {
          ps.push_back(x.first);
          ws.push_back(x.second);
     }
}


vector<item_t> random_items(int cantidad, int pesomax) {
     default_random_engine generator;
     generator.seed(random_device()());
     uniform_int_distribution<int>
          distribution(1, pesomax);
     //auto cubilete = bind ( distribution, generator );
     vector<item_t> data;
     for (int i = 0; i < cantidad; i++) {
          data.push_back(make_pair(distribution(generator),
                                   distribution(generator)));
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


void agregar_item_a_suma(item_sum_t &x, item_t const &i) {
     x.first += i.first;
     x.second += i.second;
};

void combinar_sumas (item_sum_t &x, item_sum_t const &y) {
     x.first += y.first;
     x.second += y.second;
};
