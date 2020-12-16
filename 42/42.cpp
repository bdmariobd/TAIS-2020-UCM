
// Nombre y Apellidos
//Mario Blanco

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include"Matriz.h"
#include "EnterosInf.h"
#include <unordered_map>

/*
    La solucion está basada en el algoritmo de Floyd
    Recurrencia: c k (i,j) : camino minimo del vertice i al vertice j usando solo vertices de 1 a k

    Caso base: c 0 =G
    Caso recursivo : c k (i,j) = min(c k-1(i,j) , c k-1(i,k) + c k-1(k,j))

*/
void relacion(const Matriz<EntInf> & g, Matriz<EntInf>& c) {
    int V = g.numfils();
    c = g;
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                auto temp = c[i][k] + c[k][j];
                if (temp < c[i][j]) { // pasar por el vertice k
                    c[i][j] = temp;
                } 
            }
        }
    }
    //return mayor;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int P, R;
    std::cin >> P >> R;
   if (!std::cin)  // fin de la entrada
      return false;
   Matriz<EntInf> g(P, P, Infinito);
   std::unordered_map<std::string, int> personas;
   int apariciones = 0;
   std::string p1, p2;
   for (int i = 0; i < P; ++i) g[i][i] = 0;
   for (int i = 0; i < R; ++i) {
       std::cin >> p1 >> p2;
       if (!personas.count(p1)) {
           personas[p1] = apariciones;
           ++apariciones;
       }
       if (!personas.count(p2)) {
           personas[p2] = apariciones;
           ++apariciones;
       }
       g[personas[p1]][personas[p2]] = 1;
       g[personas[p2]][personas[p1]] = 1;
       //insertar
   }
   Matriz<EntInf> c(0, 0, Infinito);
   relacion(g,c);
   EntInf sol = 0;
   for (int i = 0; i < P; ++i)
       for (int j = 0; j < P; ++j)
           sol = std::max(sol, c[i][j]);
   if (sol == Infinito) std::cout << "DESCONECTADA\n";
   else std::cout << sol << '\n';
   
   
   // escribir sol
   
   return true;
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
