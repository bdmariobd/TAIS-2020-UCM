
// Nombre y Apellidos
//Mario Blanco Dominguez
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>
#include "Digrafo.h"

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

class juego {
private:
    Digrafo g;
    int n, k;

    int bfs(int origen, int destino) { //nº vertices de camino mas corto de origen a destino. O(v+a)
        if (origen == destino) return 0; //no hay que hacer pasos
        std::vector<int> distancia(destino, -1);
        std::vector<bool> marked(n*n);
        marked[origen] = true;
        distancia[origen] = 0;
        std::queue<int> cola;
        cola.push(origen);
        while (!cola.empty()) {
            int v = cola.front();
            cola.pop();
            for (int i = 1; i <= k; ++i) {//las k tiradas del dado
                int w = v+i;
                if (w >= destino) w = destino-1;
                if (!g.ady(w).empty()) w = g.ady(w)[0]; //si tiene escalera o serpiente
                if (!marked[w]) {
                    marked[w] = true;
                    distancia[w] = distancia[v] + 1;
                    if (w == destino-1) return distancia[w];
                    else cola.push(w);
                }
            }
        }
    }


public:
    juego(int n,int k,int s,int e) :n(n),k(k),g(n*n){
        int origen, destino;//solo almaceno como adyacentes escaleras y serpientes
        for (int i = 0; i < s; ++i) {
            std::cin >> origen >> destino;
            g.ponArista(origen-1, destino-1);
        }
        for (int i = 0; i < e; ++i) {
            std::cin >> origen >> destino;
            g.ponArista(origen-1, destino-1);
        }
    }
    int minimo() {
        return bfs(0, n * n );
    }
};
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int n, k, s, e;
    std::cin >> n >> k >> s >> e;
   if (n==0)
      return false;
   std::cout<<juego(n, k, s, e).minimo()<<"\n";
   

   
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
