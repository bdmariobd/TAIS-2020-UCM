
// Nombre y Apellidos Mario Blanco

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "GrafoValorado.h"
#include "IndexPQ.h"
#include <limits>

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

class caminos {
private:
    const int INF = std::numeric_limits<int>::max();
    std::vector<int> dist;
    std::vector<int> numCam; //vector que guarda el nº de caminos con el mismo coste a un vertice
    //std::vector<AristaDirigida<int>> ult;
    GrafoValorado<int> g;
    IndexPQ<int> pq;

    void relajar(Arista<int> a, int v) {
        int w = a.otro(v);
        if (dist[w] > dist[v] + a.valor()) { 
            dist[w] = dist[v] + a.valor();
            numCam[w] = numCam[v];
            //ult[w] = a;
            pq.update(w, dist[w]); //se comporta como push si no estaba. mete el vector a la cola a visitar, cambiando su prioridad si fuese necesario
        }

        else if (dist[w] == dist[v] + a.valor()) {
            numCam[w] += numCam[v];
        }
    }
    void Dijkstra(int origen) {
        dist[origen] = 0;
        numCam[origen] = 1;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a,v);
        }
    }
public:

    caminos(int n, int a) : g(n), dist(n, INF), numCam(n,0), pq(n) {
        int v, w, valor;
        for (int i = 0; i < a; ++i) {
            std::cin >> v >> w >> valor;
            g.ponArista({ v - 1, w - 1, valor });
        }
    }
    int numCaminos() {
        Dijkstra(0);
        return numCam[g.V() - 1];
    }
};
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int n, a;
    std::cin >> n >> a;
   if (!std::cin)  // fin de la entrada
      return false;
   std::cout << caminos(n, a).numCaminos()<<'\n';
   
   
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
