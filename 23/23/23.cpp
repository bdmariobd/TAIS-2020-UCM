
// Nombre y Apellidos Mario Blanco

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "DigrafoValorado.h"
#include "IndexPQ.h"
#include <limits>
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

class navegar {
private:
    //int origen;
    const int INF = std::numeric_limits<int>::max();
    std::vector<int> dist;
    //std::vector<AristaDirigida<int>> ult;
    DigrafoValorado<int> g;
    IndexPQ<int> pq;
    std::vector<int> costes;

    void relajar(AristaDirigida<int> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor() + costes[w]) { //el coste de acceso es el del valor de la arista + el de acceso al vector
            dist[w] = dist[v] + a.valor() + costes[w];
            //ult[w] = a;
            pq.update(w, dist[w]); //se comporta como push si no estaba. mete el vector a la cola a visitar, cambiando su prioridad si fuese necesario
        }
    }
    void Dijkstra(int origen) {
        dist[origen] = 0 + costes[origen];
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }
public:
    //Dijkstra
    navegar(int n) :  g(n), dist(n, INF), pq(n),costes(n) {
        int coste, aristas;
        for (int i = 0; i < n; ++i) {
            std::cin >> coste;
            costes[i] = coste;
        }
        std::cin >> aristas;
        int v, w, valor;
        for (int i = 0; i < aristas; ++i) {
            std::cin >> v >> w >> valor;
            g.ponArista({ v-1, w-1, valor });
        }

    }
    int menorCoste() {
        Dijkstra(0);
        if (dist[g.V() - 1] == INF) return -1;
        return dist[g.V()-1];
    }
};
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int n;
    std::cin >> n;
   if (n==0)
      return false;
   
   int sol = navegar(n).menorCoste();
   if (sol == -1) std::cout << "IMPOSIBLE\n";
   else std::cout << sol << '\n';
   
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
