#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include "mochila.h"
#include <utility>

using namespace std;

int calcular_beneficio(vector<int>&ps,vector<int>&conj);
int print_vec(vector<int> v, string str) ;

int fuerza_bruta (vector<int> precios, vector<int>weights, int W) ;
int fuerza_bruta2 (vector<pair<int,int>> items, int W) ;

vector<int> random_int_vector(int size);

void copiar_items(vector<pair<int,int>> &items,
                  vector<int> &ps, vector<int> &ws);
vector<pair<int,int>> random_items(int cantidad) ;

using namespace std;
int main (int argc, char ** argv) {

     int n = 15;
     int W = 100;

     if (argc > 1)
          n = atoi(argv[1]);
     
     vector<int> ps;
     vector<int> ws;
     vector<pair<int,int>> items = random_items(n);
     copiar_items(items, ps, ws);
     // ps = { 4 , 8, 10, 2, 11, 6, 8, 3, 8, 6, 11, 21, 32};
     // ws = { 9 , 1, 20, 7, 2, 10, 8, 9, 3, 9, 7, 33, 43};

     // ps = random_int_vector(n);
     // ws = random_int_vector(n);
     cout << "n es " << n << " W es " << W << endl;
     int suma_precios = print_vec(ps, "precios: ");
     cout << "\tprecio total: " << suma_precios << endl;
     int suma_weights = print_vec(ws, "weights: ");
     cout << "\tpeso total: " << suma_weights << endl;

     int res = fuerza_bruta(ps, ws, W);
     cout << res << endl;

     // cout << "random vector de n: " << n << endl;
     // vector<int> data = random_int_vector(n);
     // for (int x : data) { cout << x << " "; }
     // cout << endl;


     int res2 = fuerza_bruta2(items, W);
     cout << "con pares: " << res2 << endl;

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

void copiar_items(vector<pair<int,int>> &items,
                  vector<int> &ps, vector<int> &ws) {
     for (pair<int,int> x : items) {
          ps.push_back(x.first);
          ws.push_back(x.second);
     }

}

vector<pair<int,int>> random_items(int cantidad) {
     default_random_engine generator;
     generator.seed(random_device()());
     uniform_int_distribution<int>
          distribution(1, 100);
     //auto cubilete = bind ( distribution, generator );
     vector<pair<int,int>> data;
     for (int i = 0; i < cantidad; i++) {
          data.push_back(make_pair(distribution(generator),
                                   distribution(generator)));
     }
     return data;
}
