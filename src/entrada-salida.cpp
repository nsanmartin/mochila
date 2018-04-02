#include <random>
#include <iostream>
#include "mochila.h"
#include <string>
#include <fstream>
using namespace std;

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



// void leer_parametros(int &W, vector<item_t> &items, string filename) {
//      int n, i = 0;
//      string line;
     
//      ifstream file;
//      file.open(filename);
//      if (!file) {
//           cerr << "No se pudo leer " << filename << endl;
//           exit(1);
//      }
     
//      if (!(file >> n) ) {
//           cerr << "Falta n en " << filename << endl;
//           exit(1);

//      }
//      if (!(file >> W)) {
//           cerr << "Falta W en " << filename << endl;
//           exit(1);
//      }


//      int w, p;
//      while (file >> p && file >> w) {
//           if (i++ == n) {
//                cerr << "advertencia: hay mas numeros en el archivo\n"
//                     << "             que los que dice su primera linea"
//                     << endl;
//                break;
//           }
//           items.push_back(make_pair(w,p));
//      }

//      if (i != n )
//           cerr << "Faltan numeros o no pueden leerse\n";
// }


void leer_parametros_stream(int &W, vector<item_t> &items,
                            istream & file) {
     int n, i = 0;
     string line;
     
     //ifstream file;
     // if(!file.is_open()) {
     //      cerr << "No se pudo leer archivo" << endl;
     //      exit(1);
     // }
     
     if (!(file >> n) ) {
          cerr << "Falta n en input file" << endl;
          exit(1);

     }
     if (!(file >> W)) {
          cerr << "Falta W en input file" << endl;
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


