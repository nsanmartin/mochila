#ifndef _MOCHILA_H
#define _MOCHILA_H

#include <utility>
#include <vector>
#include <string>
#include <fstream>

typedef std::pair<int,int> item_t;
typedef std::pair<int,int> item_sum_t;

typedef struct mochila {
     item_sum_t afuera;
     item_sum_t adentro;
     item_sum_t total;
} mochila;

using namespace std;

int calcular_beneficio(vector<int>&ps,vector<int>&conj);
int print_vec(vector<int> v, string str) ;
int print_items(vector<item_t> v);

int fuerza_bruta(vector<item_t> &items, int W) ;
int fuerza_bruta2 (vector<item_t> &items, int W) ;
int fuerza_bruta3 (vector<item_t> &items, int W) ;
int fuerza_bruta4 (vector<item_t> &items, int W) ;
int backtracking  (vector<item_t> &items, int W) ;
int backtracking2  (vector<item_t> &items, int W) ;
int dinamica (vector<item_t> &items, int W);

vector<int> random_int_vector(int size);

void copiar_items(vector<item_t> &items,
                  vector<int> &ps, vector<int> &ws);

vector<item_t> random_items(int cantidad);
vector<item_t> random_items(int cantidad, int pesomax);

int meet_middle (vector<item_t> &items, int W) ;

// mochila random
int rand_int_mod(int n) ;
vector<int> random_int_vector(int size) ;
void copiar_items(vector<item_t> &items,
                  vector<int> &ps, vector<int> &ws) ;
vector<item_t> random_items(int cantidad) ;

void agregar_item_a_suma(item_sum_t &x, item_t const &i) ;


//io

void leer_parametros(int &W, vector<item_t> &items, string filename) ;
void leer_parametros_stream(int &W, vector<item_t> &items,
                            istream & file) ;


// tests
void test0(int n, int W);
void test1(int n, int W) ;
void test2(int n, int W) ;
void test3(int n, int W) ;
void test4(int n, int W) ;
void test5(int n, int W) ;

void comparar_algotirmos(int W, vector<item_t> items) ;
void muestrear_algoritmos(int W, vector<item_t> items) ;

#endif
