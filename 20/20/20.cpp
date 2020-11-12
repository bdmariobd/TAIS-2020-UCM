
// Nombre y Apellidos Mario Blanco TAIS 13

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include<string>
#include "ConjuntosDisjuntos.h"

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
const std::vector<std::pair<int, int>> direcciones = { {0,1},{0,-1}, {1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1} };
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int f, c,maximo=0;
    std::cin >> f >> c;
   if (!std::cin)  // fin de la entrada
      return false;
   std::vector<std::vector<bool>> fondo(f, std::vector<bool>(c));
   ConjuntosDisjuntos cjto(f * c);
   std::cin.ignore();
   bool encontreMax = false;
   for (int i = 0; i < f; ++i) {
       std::string linea;
       std::getline(std::cin, linea, '\n');

       for (int j = 0; j < c;++j) {
           if (linea.at(j) == '#') { //mancha de petroleo
               encontreMax = true;
               fondo[i][j] = true;
               int posUnaDim = (i * c + j);
               for (auto dir : direcciones) {
                   int iDir = i + dir.first, jDir = j + dir.second;
                   int posUnaDimDir = ((iDir)*c + (jDir));
                   if (iDir >= 0 && jDir >= 0 && iDir < f && jDir < c && fondo[iDir][jDir] && !cjto.unidos(posUnaDim,posUnaDimDir)) {
                       cjto.unir(posUnaDim, posUnaDimDir);
                       maximo = std::max(maximo, cjto.cardinal(posUnaDim));
                   }
               }
           }
       }

   }
   if (encontreMax && maximo==0) maximo = 1;
   std::cout << maximo<<" ";
   int casos;
   std::cin >> casos;
   if (maximo == 0 && casos > 0) maximo = 1;
   while (casos--) {
       int fila, columna;
       std::cin >> fila >> columna;
       fila--; columna--;
       fondo[fila][columna] = true;
       int posUnaDim = (fila * c + columna);
       for (auto dir : direcciones) {
           int iDir = fila + dir.first, jDir = columna + dir.second;
           int posUnaDimDir = ((iDir)*c + (jDir));
           if (iDir >= 0 && jDir >= 0 && iDir < f && jDir < c && fondo[iDir][jDir] && !cjto.unidos(posUnaDim, posUnaDimDir)) {
               cjto.unir(posUnaDim, posUnaDimDir);
               maximo = std::max(maximo, cjto.cardinal(posUnaDim));
           }
       }
       std::cout << maximo << " ";
   }
   std::cout << '\n';
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
