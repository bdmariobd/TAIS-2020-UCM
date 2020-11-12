
// Nombre y Apellidos
//Mario Blanco Dominguez, TAIS13

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
/*
    Para resolver el problema, se hace un recorrido en anchura del arbol para acceder y contar a todos los nodos alcanzables
    Los vertices del grafo representan los nodos de conexion, y las aristas las conexiones entre ellos
    La solucion, es decir, el numero de inancalzables, son los nodos totales - los nodos alcanzados segun el ttl.
*/
#include <iostream>
#include <fstream>
#include"Grafo.h"
#include <queue>

class red {
private:

    Grafo g;
    void leeGrafo(int a) {
        for (int i = 0; i < a; ++i) {
            int n1, n2;
            std::cin >> n1>> n2;
            g.ponArista(n1 - 1, n2 - 1);
        }
    }

    int bfs(int origen, const int &ttl) { //Coste: O(v+a) siendo v el numero de nodos y a las aristas. Pese a que puede cortar antes la busqueda, el caso peor es que todos sean visitados
        int recorridos = 1;
        std::queue<int> cola;
        std::vector<bool> marcas(g.V());
        std::vector<int>dist(g.V());
        dist[origen] = 0;
        cola.push(origen);
        marcas[origen] = true;
        while (!cola.empty()) {
            int v = cola.front();
            cola.pop();
            for (int w: g.ady(v)) {
                if (!marcas[w] && dist[v]+1<=ttl) {
                    ++recorridos;
                    dist[w] = dist[v] + 1;
                    marcas[w] = true;
                    cola.push(w);
                }
            }
        }
        return recorridos;

    }
public:
    red(int n, int c): g(n){
        leeGrafo(c);
    }

    void consultas() {
        int k, origen,ttl;
        std::cin >> k;
        for (int i = 0; i < k; ++i) { //Coste: O (K* coste bfs), siendo k el nº de consultas
            std::cin >> origen >> ttl;
            std::cout << g.V() - bfs(origen-1,ttl)<<'\n';
        }
        std::cout << "---\n";
    }
};
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int n, c, k;
    std::cin >> n;
   if (!std::cin)  // fin de la entrada
      return false;
   std::cin >> c;
   red r(n, c);
   r.consultas();
   
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
