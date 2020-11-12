
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>
#include "Digrafo.h"
class calculadora {
private:
    const int MAX = 10000;
    const int inf = -1;
    int adyacente(int v, int op) {
        switch (op) {
            case 0:return(v + 1) % MAX;
            case 1: return (v * 2) % MAX;
            case 2: return (v / 3);
        }
    }

    int bfs(int origen, int destino) { //nº vertices de camino mas corto de origen a destino
        if (origen == destino) return 0; //no hay que hacer pasos
        std::vector<int> distancia(MAX, inf);
        distancia[origen] = 0;
        std::queue<int> cola;
        cola.push(origen);
        while (!cola.empty()) {
            int v = cola.front();
            cola.pop();
            for (int i = 0; i < 3; ++i) {//el grafo tiene 3 adyacentes, que son las 3 operaciones
                int w = adyacente(v, i);
                if (distancia[w] == inf) {
                    distancia[w] = distancia[v] + 1;
                    if (w == destino) return distancia[w];
                    else cola.push(w);
                }
            }
        }
    }

public:
    int sol(int a, int b) {
        return bfs(a, b);
    }
};
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int origen, destino;
    std::cin >> origen >> destino;
   if (!std::cin)  // fin de la entrada
      return false;
   std::cout << calculadora().sol(origen, destino) << '\n';
   
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
