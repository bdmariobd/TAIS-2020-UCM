
// Nombre y Apellidos Mario Blanco Dominguez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include<vector>
#include"Matriz.h"
#include "EnterosInf.h"
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

/*
    tiradas(i,j) es el numero menor de tiradas para llegar a j puntos contando sectores de 1 a i

    recursion

    tiradas(i,j)= tiradas(i-1 , j) -> sector[i]>j (se pasa)
                  min(tiradas(i-1,j) , tiradas(i, j-sector[i] +1)) si sector[i]<=j

    casos base :
    tiradas (0,j) = infinito
    tiradas(i,0)=0
*/
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int valor, s, sect;
    std::cin >> valor>> s;
   if (!std::cin)  // fin de la entrada
      return false;
   std::vector<int> sector;
   sector.push_back(0); 
   for (int i = 0; i < s; ++i) {
       std::cin >> sect;
       sector.push_back(sect);
   }
   Matriz<EntInf> tiradas(s + 1, valor + 1, Infinito);

   tiradas[0][0] = 0;

   for (int i = 1; i <= s; ++i) {
       tiradas[i][0] = 0;
       for (int j = 1; j <= valor; ++j) {
           if (sector[i] > j) tiradas[i][j] = tiradas[i - 1][j];
           else tiradas[i][j] = std::min(tiradas[i - 1][j], tiradas[i][j - sector[i]] +1 );
       }
   }
   if (tiradas[s][valor] == Infinito) std::cout << "Imposible\n";
   else {
       std::cout << tiradas[s][valor] << ": ";
       std::vector<int> veces_sector(s+1,0);
       int j = valor, i =s;
       while (j > 0) {
           /*if (sector[i] <= j) { //se ha usado el sector i
               j -= sector[i];
               ++veces_sector[i];
           }
           else --i; //no se ha usado el sector i, prueba con el anterior*/
           if (j>= sector[i] && tiradas[i][j] == tiradas[i][j - sector[i]] + 1) {
               j -= sector[i];
               ++veces_sector[i];
           }
           else --i;
       }

       for (int i = s; i > 0; --i) {
           for (int veces = 0; veces < veces_sector[i]; ++veces) {
               std::cout << sector[i] << " ";
           }
       }
       std::cout<<'\n';
   }
   
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
