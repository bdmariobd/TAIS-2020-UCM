
// Nombre y Apellidos Mario Blanco TAIS13

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "Grafo.h"
#include<vector>


class Problema {
private:
    Grafo g;
    std::vector<bool> visit;
    std::vector<int>ant;
    int origen;
    bool esLibre = true;
    int nVisit = 1;

    void leeGrafo(int a) {
        int p1, p2;
        for (int i = 0; i < a; ++i) {
            std::cin >> p1 >> p2;
            g.ponArista(p1, p2);
        }
    }
    void dfs(int v) { //el coste es de O(v+a)
        visit[v] = true;
        for (int w : g.ady(v)) {
            if (!visit[w]) {
                ant[w] = v;
                dfs(w);
                ++nVisit;
            }
            else { // si el anterior del actual no es el adyacente, hay mas de un camino de v a w
                if (ant[v] != w) esLibre = false;
            }
        }
    }
    bool conexo() {
        return nVisit == g.V();
    }
    bool aciclico() {
        return conexo() && g.A() == g.V() - 1;
    }
public:
    
    Problema(int v,int a) :g(v), visit(g.V()), ant(g.V()),origen(0) { 
        leeGrafo(a);
        dfs(origen); 
    }

    
    bool libre() {
        return aciclico();
    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int v, a;
    std::cin >> v;
   if (!std::cin)  // fin de la entrada
      return false;
   std::cin >> a;
   Problema p(v,a);

   if (p.libre())std::cout << "SI\n";
   else std::cout << "NO\n";
   
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
