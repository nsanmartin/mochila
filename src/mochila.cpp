#include <iostream>
#include <numeric>
#include <random>

#include "mochila.h"

using namespace std;

int calcular_beneficio(vector<int>&ps,vector<int>&conj);
int print_vec(vector<int> v, string str) ;

int fuerza_bruta (vector<int> precios, vector<int>weights, int W) ;
int fuerza_bruta2 (vector<pair<int,int>> items, int W) ;

vector<int> random_int_vector(int size);

void copiar_items(vector<pair<int,int>> &items,
                  vector<int> &ps, vector<int> &ws);
vector<pair<int,int>> random_items(int cantidad) ;
void test0(int n, int W);
using namespace std;
int main (int argc, char ** argv) {

     int n = 15;
     int W = 100;

     if (argc > 1)
          n = atoi(argv[1]);
     for (int i = 0; i < 99999 ; i++) {
          test0(n, W);
     }

}

void test0(int n, int W) {

     vector<int> ps;
     vector<int> ws;
     vector<pair<int,int>> items = random_items(n);
     copiar_items(items, ps, ws);
     // cout << "n es " << n << " W es " << W << endl;
     // int suma_precios = print_vec(ps, "precios: ");
     // cout << "\tprecio total: " << suma_precios << endl;
     // int suma_weights = print_vec(ws, "weights: ");
     // cout << "\tpeso total: " << suma_weights << endl;
     // for (int i = 0; i < 999999; i++) {
     int res = fuerza_bruta(ps, ws, W);
     // cout << res << endl;

     // cout << "random vector de n: " << n << endl;
     // vector<int> data = random_int_vector(n);
     // for (int x : data) { cout << x << " "; }
     // cout << endl;


     int res2 = fuerza_bruta2(items, W);
     // cout << "con pares: " << res2 << endl;

     if (res != res2) {
          cerr << "Error!!! fb y fb2 no coincieden!";
          cerr << "res: " << res << " res2: " << res2;
          exit(1);
     } else {
          cout << res2 << " ";
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
