
// Nombre y Apellidos
//Mario Blanco Dominguez, TAIS13

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
/*
*/
#include <iostream>
#include <fstream>
#include"Grafo.h"
#include <queue>

class red {
private:
    std::vector<bool> visit;
    std::vector<int> sol;
    Grafo g;
    void leeGrafo(int a) {
        int tam, k;
        for (int i = 0; i < a; ++i) {
            std::cin >> tam;
            if (tam > 0) {
                int a1, a2;
                std::cin >> a1;
                for (int j = 1; j < tam; ++j) {
                    std::cin >> a2;
                    g.ponArista(a1 - 1, a2 - 1);
                    a1 = a2;
                }
            }
        }
    }

    int dfs(int origen, std::vector<int> & conexo) { //Coste: O(v+a) 
        visit[origen] = true;
        int amigos = 1;
        for (int w: g.ady(origen)) {
            if (!visit[w]) {
                amigos += dfs(w,conexo);
                visit[w] = true;
                conexo.push_back(w);
            }
        }
        return amigos;
    }

public:
    red(int n, int m): g(n),visit(n), sol(n){
        leeGrafo(m);
        int amigos = 1;
        for (int i = 0; i < n; ++i) {
            std::vector<int> conexo;
            if (!visit[i]) {
                conexo.push_back(i);
                int amigos=dfs(i, conexo);
                for (int i : conexo) sol[i] = amigos;
            }
                
        }
    }

    void muestraSol() {
        for (int i : sol) std::cout << i << " ";
        std::cout << '\n';
    }
   
};
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int n, m;
    std::cin >> n;
   if (!std::cin)  // fin de la entrada
      return false;
   std::cin >> m;
   red r(n, m);
   r.muestraSol();
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
