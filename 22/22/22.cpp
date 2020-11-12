
// Mario Blanco Dominguez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include<queue>
#include "ConjuntosDisjuntos.h"
#include "GrafoValorado.h"


class arch {
private:
    GrafoValorado<int> g;
    int krustal() {
        int coste = 0, visit=0;
        ConjuntosDisjuntos cjto(g.V());
        auto ar = g.aristas();
        std::priority_queue<Arista<int>, std::vector<Arista<int>>, std::greater<Arista<int>>> cola(ar.begin(),ar.end());
        while (!cola.empty()) {
            auto a = cola.top();
            cola.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjto.unidos(v, w)) {
                cjto.unir(v, w);
                ++visit;
                coste += a.valor();
                if (visit == g.V() - 1) return coste;
            }
        }
        return -1;

    }
public:
    arch(int i, int p): g(i){
        while (p--) {
            int a, b, valor;
            std::cin >> a >> b >> valor;
            g.ponArista({ a - 1, b - 1, valor });
        }

    }

    int costeMinPuentes() {
        if (g.V() == 1) return 0;
        return krustal();
    }
};
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int i, p;
    std::cin >> i >> p;
   // leer los datos de la entrada
   
   if (!std::cin)  // fin de la entrada
      return false;
   
   int sol = arch(i, p).costeMinPuentes();
   if (sol == -1) std::cout << "No hay puentes suficientes\n";
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
