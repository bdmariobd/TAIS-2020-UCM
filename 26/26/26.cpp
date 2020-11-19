
// Nombre y Apellidos Mario Blanco 

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <limits>
#include"DigrafoValorado.h"
#include "IndexPQ.h"

class caminoMenor {
private:
    const int INF = std::numeric_limits<int>::max();
    std::vector<int> dist;
    //std::vector<int> distVuelta;
    //std::vector<AristaDirigida<int>> ult;
    //DigrafoValorado<int> g;
    IndexPQ<int> pq;

    void relajar(const AristaDirigida<int> &  a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor() ) { 
            dist[w] = dist[v] + a.valor();
            //ult[w] = a;
            pq.update(w, dist[w]); //se comporta como push si no estaba. mete el vector a la cola a visitar, cambiando su prioridad si fuese necesario
        }
    }
    
    void Dijkstra(const DigrafoValorado<int> & g , int origen) {
        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }
    
public:
    caminoMenor(int n, const DigrafoValorado<int> & g, int origen):dist(n,INF), pq(n) {
        Dijkstra(g, origen);
    }

    int esfuerzo(int destino) {//si devuelve -1,es intransitable
        if (dist[destino] == INF) return -1;
        return dist[destino];
    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int n, a, origen,destino,coste,paquetes;
    std::cin >> n >> a;
   if (!std::cin)  // fin de la entrada
      return false;
   DigrafoValorado <int> g(n);
   while (a--) {
       std::cin >> origen >> destino >> coste;
       g.ponArista({ origen-1,destino-1,coste });
   }
   std::cin >> origen >> paquetes;
   //auto origen_a_resto = caminoMenor(n).todos(origen-1, g);
   int esfuerzo = 0;
   caminoMenor cartero(n, g,origen-1);
   caminoMenor carteroVuelta(n, g.inverso(), origen - 1);
   while (paquetes--) {
       std::cin >> destino;
       if (esfuerzo != -1) {
           int esfuerzoPaq = cartero.esfuerzo(destino - 1), esfuerzoVuelta = carteroVuelta.esfuerzo(destino-1);
           if (esfuerzoPaq == -1 || esfuerzoVuelta==-1) esfuerzo = -1;
           else esfuerzo += esfuerzoPaq + esfuerzoVuelta;
       }
   }
   if (esfuerzo == -1) std::cout << "Imposible\n";
   else std::cout << esfuerzo << '\n';
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
