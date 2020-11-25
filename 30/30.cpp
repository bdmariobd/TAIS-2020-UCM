
// Nombre y Apellidos MARIO BLANCO 

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include<vector>
#include <algorithm>

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
/*
    Para resolver el problema se ordenan ambos vectores de menor a mayor.
    Asi conseguimos minimizar la diferencia de la resta en valor absoluto
    de cada esquiador con el tamaño de sus esquis, manteniendo esta suma lo mas
    pequeña posible. 

    El coste es de (2 N log n (ordenacion) + N(recorrer) -> coste O(N log n)
*/
int sumaDifs(std::vector < int>& esquiadores, std::vector<int>& esquis) {
    std::sort(esquiadores.begin(), esquiadores.end(), std::less<int>());
    std::sort(esquis.begin(), esquis.end(), std::less<int>());

    int suma = 0;

    for (int i = 0; i < esquiadores.size(); ++i) {
        suma += std::abs(esquiadores.at(i) - esquis.at(i));
    }
    return suma;
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int n,dato;
    std::cin >> n;
   if (n==0)
      return false;
   std::vector<int> esquiadores, esquis;
   for (int i = 0; i < n; ++i) {
       std::cin >> dato;
       esquiadores.push_back(dato);
    }
   for (int i = 0; i < n; ++i) {
       std::cin >> dato;
       esquis.push_back(dato);
   }
   // escribir sol
   std::cout << sumaDifs(esquiadores, esquis) << '\n';
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
