#ifndef _MOCHILA_H
#define _MOCHILA_H

#include <utility>
#include <vector>


typedef std::pair<int,int> item_t;
typedef std::pair<int,int> item_sum_t;

using namespace std;

int calcular_beneficio(vector<int>&ps,vector<int>&conj);
int print_vec(vector<int> v, string str) ;

int fuerza_bruta (vector<int> precios, vector<int>weights, int W) ;
int fuerza_bruta2 (vector<item_t> &items, int W) ;

vector<int> random_int_vector(int size);

void copiar_items(vector<item_t> &items,
                  vector<int> &ps, vector<int> &ws);
vector<item_t> random_items(int cantidad) ;
void test0(int n, int W);

int meet_middle (vector<item_t> &items, int W) ;


#endif
