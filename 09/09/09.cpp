
// Nombre y Apellidos
//Mario Blanco
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
#include<math.h>

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
struct musicos {
    int part, m;
};

int atril(const musicos& m) {
    return m.m % m.part == 0 ? m.m / m.part : (m.m / m.part) + 1;
}
bool operator> (const musicos &m1, const musicos& m2) { // m1 mas prioritario que m2
    return atril(m1) > atril(m2);
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int p, n;
    std::cin >> p;
   if (!std::cin)  // fin de la entrada
      return false;
   std::cin >> n;
   PriorityQueue<musicos, std::greater<musicos>> orquesta;
   int m;
   for (int i = 0; i < n; ++i) {
       std::cin >> m;
       orquesta.push({ 1,m });
   }
   p -= n;
   while (p != 0) {
       musicos m = orquesta.top();
       orquesta.pop();
       m.part++;
       orquesta.push(m);
       --p;
   }
   musicos sol = orquesta.top();
   std::cout << atril(sol)<< '\n';
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
