
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>


#include "ColaMedianas.h" // propios o los de las estructuras de datos de clase

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int n,valor;
    std::cin >> n;
   if (!std::cin)  // fin de la entrada
      return false;
   
   ColaMedianas cola;
   for (int i = 0; i < n; ++i) {
       std::cin >> valor;
       if (valor == 0) {
           int mediana = cola.mediana();
           if(mediana==-1) std::cout <<"ECSA ";
           else std::cout << cola.mediana()<<" ";
           cola.quitarMediana();
       }
       else cola.insertar(valor);
   }
   
   std::cout << '\n';
   
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
