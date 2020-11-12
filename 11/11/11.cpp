
// Nombre y Apellidos
//Mario BLanco TAIS13

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "Grafo.h"

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
class Problema {
private:
    Grafo g;
    std::vector<bool> visit;
    std::vector<int>ant;

    void leeGrafo(int a) {
        int p1, p2;
        for (int i = 0; i < a; ++i) {
            std::cin >> p1 >> p2;
            p1--; p2--;
            g.ponArista(p1, p2);
        }
    }
    int dfs(int v) { //el coste es de O(v+a)
        visit[v] = true;
        int personas = 1;
        for (int w : g.ady(v)) {
            if (!visit[w]) {
                ant[w] = v;
                personas+= dfs(w);
            }
        }
        return personas;
    }
public:
    Problema(int v,int a) :g(v), visit(g.V()), ant(g.V()) {
        leeGrafo(a);
    }
    int mayorGrupo() { 
        int mayor = 0;
        for (int i = 0; i < g.V(); ++i) {
            if (!visit[i])//si no visito, recorro un grafo conexo entero
                mayor = std::max(mayor, dfs(i));
        }
        return mayor;
    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int v, a;
    std::cin >> v >> a;
    Problema p(v,a);
    std::cout << p.mayorGrupo() << '\n';
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
