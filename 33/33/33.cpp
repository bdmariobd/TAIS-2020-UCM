
// Nombre y Apellidos Mario Blancoo

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(std::vector<int> & pilas, int umbral) {
    std::sort(pilas.begin(), pilas.end());
    int ok = 0, i = 0, j =pilas.size() -1;
    while (i < j) {
        if (pilas[i] + pilas[j] >= umbral) { //si vale descarto las 2 pilas
            ++i; --j;
            ++ok;
        }
        else { //si no vale, solo descarto la pila de menor valor
            ++i;
        }
    }
    return ok;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
   
   // leer los datos de la entrada
    int n, v,pila;
    std::cin >> n >> v;
    std::vector<int> pilas;
    while (n--) {
        std::cin >> pila;
        pilas.push_back(pila);
    }
    std::cout << resolver(pilas, v) << '\n';
   // escribir solución
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
