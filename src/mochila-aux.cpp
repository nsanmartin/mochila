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

int print_vec(vector<int> v, string str) {
     int suma = 0;
     cout << str;
     for (int x : v) {
          suma += x;
          cout << x << " " ;
     }
     cout << endl;
     return suma;
}


int print_items(vector<item_t> v) {
     int suma = 0;
     for (item_t x : v) {
          cout << x.first << "/" << x.second << " ";
     }
     cout << endl;
     return suma;
}

void leer_parametros(int &W, vector<item_t> &items, string filename) {
     int n, i = 0;
     string line;
     
     ifstream file;
     file.open(filename);
     if (!file) {
          cerr << "No se pudo leer " << filename << endl;
          exit(1);
     }
     
     if (!(file >> n) ) {
          cerr << "Falta n en " << filename << endl;
          exit(1);

     }
     if (!(file >> W)) {
          cerr << "Falta W en " << filename << endl;
          exit(1);
     }


     int w, p;
     while (file >> p && file >> w) {
          if (i++ == n) {
               cerr << "advertencia: hay mas numeros en el archivo\n"
                    << "             que los que dice su primera linea"
                    << endl;
               break;
          }
          items.push_back(make_pair(w,p));
     }

     if (i != n )
          cerr << "Faltan numeros o no pueden leerse\n";
}
