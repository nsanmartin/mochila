#include <iostream>
#include <vector>
#include <numeric>

#include "mochila.h"

using namespace std;

int calcular_beneficio(vector<int>&ps,vector<int>&conj);
int print_vec(vector<int> v, string str) ;

int fuerza_bruta (vector<int> precios, vector<int>weights, int W) ;

using namespace std;
int main (int argc, char ** argv) {
     int n = 5;
     int W = 100;
     
     vector<int> ps(n);
     vector<int> ws(n);

     ps = { 4 , 8, 10, 2, 11, 6, 8, 3, 8, 6, 11, 21, 32};
     ws = { 9 , 1, 20, 7, 2, 10, 8, 9, 3, 9, 7, 33, 43};
     
     cout << "n es " << n << " W es " << W << endl;
     int suma_precios = print_vec(ps, "precios: ");
     cout << "\tprecio total: " << suma_precios << endl;
     int suma_weights = print_vec(ws, "weights: ");
     cout << "\tpeso total: " << suma_weights << endl;

     int res = fuerza_bruta(ps, ws, W);
     cout << res << endl;
}

namespace mochila {
     
     
     
}
