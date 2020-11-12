
// Nombre y Apellidos Mario Blanco TAIS13

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "GrafoValorado.h"



class reparto {
private:
    GrafoValorado<int> g;
    std::vector<bool> visit;
    void dfs (int origen, int destino, int anchura) {
        //if (origen == destino) return true;
        visit[origen] = true;
        for (auto a : g.ady(origen)) {
            if (a.valor() >= anchura) {
                int w = a.otro(origen);
                if (!visit[w]) {
                     dfs(w, destino, anchura);
                }

            }
        }
        
    }
public:
    reparto(GrafoValorado<int>grafo,int v, int e):visit(v),g(0) {
        g = grafo;
    }

    bool puede(int origen, int destino, int anchura) {
        dfs(origen, destino, anchura);
        return visit[destino];
    }
};
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int v, e;
    std::cin >> v;
   if (!std::cin)  // fin de la entrada
      return false;
   std::cin >> e;

   GrafoValorado<int> g(v);
   for (int i = 0; i < e; ++i) {
       int a, b, valor;
       std::cin >> a >> b >> valor;
       g.ponArista({ a - 1,b - 1,valor });
   }


   
   int casos;
   std::cin >> casos;
   while (casos--) {
       reparto r(g, v, e);
       int a, b, valor;
       std::cin >> a >> b >> valor;
       if (r.puede(a-1, b-1, valor)) std::cout << "SI\n";
       else std::cout << "NO\n";
   }
   
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
