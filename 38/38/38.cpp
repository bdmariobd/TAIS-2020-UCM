
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "Matriz.h"
#include "EnterosInf.h"
#include <vector>
/*
    bombilla(i,j) -> coste minimo de la instalacion con j potencia usando hasya la bombilla i
    casos base: bombilla (0,j) = infinito
    bombilla(i,0) = 0

    recursion si potencia[i]>j -> bombillas(i,j) = bombillas (i-1,j)
    si potencia[i]<=j -> bombillas(i,j) = minimo( bombillas (i-1,j) , bombillas(i,j- potencia[i] + coste[i])

*/

struct bombilla {
    int coste, power;
};
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int N, PMax, PMin;
    std::cin >> N >> PMax >> PMin;
   if (!std::cin)  // fin de la entrada
      return false;
   
   std::vector<bombilla> v(N);
   for (int i = 0; i < N; i++) {
       std::cin >> v[i].power;
   }
   for (int i = 0; i < N; i++) {
       std::cin >> v[i].coste;
   }
   
   Matriz<EntInf> bombilla(N+1, PMax + 1, Infinito);

   bombilla[0][0] = 0;

   for (int i = 1; i <= N; ++i) {
       bombilla[i][0] = 0;
       for (int j = 1; j <= PMax; ++j) {
           if (v[i-1].power > j) bombilla[i][j] = bombilla[i - 1][j];
           else bombilla[i][j] =std::min( bombilla[i - 1][j] , bombilla[i][j - v[i-1].power]  + v[i-1].coste);
       }
   }

   auto minimo = bombilla[N][PMin];
   int potencia = PMin;
   for (int j = PMin; j <= PMax; j++) { //pruebo si con mas potencia sale mas barato
       if (minimo > bombilla[N][j]) {
           minimo = bombilla[N][j];
           potencia = j;
       }
   }
   if (minimo == Infinito) std::cout << "IMPOSIBLE\n";
   else std::cout << minimo << " " << potencia << '\n';
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
