
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include<limits>
#include "GrafoValorado.h"
#include "IndexPQ.h"
#include <queue>
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

/*
    se realiza un bfs para comprobar si hay camino, y, en caso de haberlo, guardar la distancia minima en numero de vertices.
    Tras ejecutar el bfs, se ejecuta el algoritmo de Dijkstra para calcular el camino de menor coste desde el origen al resto de aristas
    El Dijkstra esta modificado, ya que guarda tambien el nº de vertices al camino minimo (que no tiene porque coincidir con el bfs)

    Tras la ejecucion de los dos algoritmos, escribo el coste minimo del Dijkstra. Despues, compruebo si el camino minimo que el Dijkstra
    se ha guardado coincide con el calculado por el BFS, para escribir SI o NO.

*/
class mejorCamino{ //recibe el grafo ya leido
private:
    const int INF = std::numeric_limits<int>::max();
    std::vector<int> distanciaBFS;//bfs. Si es INF, indica que no se ha marcado. Guarda la distancia en nº vertices a cualquier vertice desde origen
    std::vector<std::pair<int,int>> dist; //Dijkstra. Guarda la distancia en coste a cualquier vertice y la dist en nºvertices. 1st coste 2nd nº vertices
    GrafoValorado<int> g;
    IndexPQ<std::pair<int,int>> pq; //Dijkstra


    void relajar(Arista<int> a, int v) {
        int w = a.otro(v);
        if (dist[w].first > dist[v].first + a.valor()) {
            dist[w].first = dist[v].first + a.valor(); //cambia el coste
            dist[w].second = dist[v].second + 1; //guarda el numero de vertices al camino de menor coste
            pq.update(w, dist[w]); //se comporta como push si no estaba. mete el vector a la cola a visitar, cambiando su prioridad si fuese necesario
        }

        else if (dist[w].first == dist[v].first + a.valor()) {
            dist[w].second = dist[v].second + 1; //guarda el numero de vertices al camino de menor coste
            pq.update(w, dist[w]);
        }
    }
    void Dijkstra(int origen) { //coste de O(a * logV)
        dist[origen] = {0,0};
        pq.push(origen, {0,0});
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a, v);
        }
    }

    void bfs(int origen) { //nº vertices de camino mas corto de origen al resto de vertices.El coste es de O(v+a)
        distanciaBFS[origen] = 0;
        std::queue<int> cola;
        cola.push(origen);
        while (!cola.empty()) {
            int v = cola.front();
            cola.pop();
            for (auto ar : g.ady(v)) {
                int w = ar.otro(v);
                if (distanciaBFS[w] == INF) {
                    distanciaBFS[w] = distanciaBFS[v] + 1;
                    cola.push(w);
                }
            }
        }
    }

public:
    void resuelveCaso(int origen, int destino) {
        bfs(origen); 
        if (distanciaBFS[destino] != INF) {
            Dijkstra(origen);
            std::cout << dist[destino].first<< " ";
            if (dist[destino].second == distanciaBFS[destino]) {
                std::cout << "SI\n";
            }
            else {
                std::cout << "NO\n";
            }
        }
        else {
            std::cout << "SIN CAMINO\n";
        }
    }
    mejorCamino(GrafoValorado<int> grafo, int n) :g(0), distanciaBFS(n, INF), pq(n), dist(n, { INF,0 }) {
        g = grafo;

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
   int v, w, valor;
   GrafoValorado<int> g(n);
   for (int i = 0; i < a; ++i) {
       std::cin >> v >> w >> valor;
       g.ponArista({ v - 1, w - 1, valor });
   }
   
   int consultas;
   std::cin >> consultas;
   while (consultas--) {
       int origen, destino;
       std::cin >> origen >> destino;
       mejorCamino(g,n).resuelveCaso(origen-1, destino-1);
   }
   // escribir sol
   std::cout << "---\n";
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
