
// Nombre y Apellidos
//Mario Blanco Dominguez
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include<exception>
#include "TreeSet_AVL.h"



// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int n,valor;
    std::cin >> n; //num nodos a leer
   if (n==0)
      return false;
   Set<int> arbol;

   for (int i = 0; i < n; ++i) {  //inserccion en orden de los nodos
       std::cin >> valor;
       arbol.insert(valor);
   }

   std::cin >> n; //num de valores a consultar

   for (int i = 0; i < n; ++i) {
       std::cin >> valor;
       try {
           int sol = arbol.kesimo(valor);
           std::cout << sol<<'\n';
       }
       catch (std::out_of_range& e) {
           std::cout << e.what()<<"\n";
       }
   }
   std::cout << "---\n";
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
