
// Nombre y Apellidos Mario Blanco

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include "Matriz.h"

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
/*
    tablones(i,j) = minimo esfuerzo en cortar el tablon desde los corte i a j

    caso base: tablones(i,i+1)=0

    caso recursivo: tablones(i,j)= min(tablones(i,k) + tablones(k,j) + 2*(punto[j]- punto[i])) siendo i<=k<j
*/

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int L, N,corte;
    std::cin >> L >> N;
   if (L==0)
      return false;
   std::vector<int> punto;
   punto.push_back(0);
   for (int i = 0; i < N;++i) {
       std::cin >> corte;
       punto.push_back(corte);
   }
   punto.push_back(L);
   int tam = punto.size();
   Matriz<int> tablones(tam, tam, 0);
   
   for (int d = 2; d <= tam; ++d) {
       for (int i = 0; i < tam - d; ++i) {
           int j = i + d;
           int min = 100000000;
           for (int k = i + 1; k < j; ++k) {
               int candidato = tablones[i][k] + tablones[k][j] + 2 * (punto[j] - punto[i]);
               if (candidato < min) {
                   min = candidato;
                   tablones[i][j] = candidato;
               }
           }     
       }
   }
   
   std::cout << tablones[0][tam-1] << '\n';
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
