
// Nombre y Apellidos
//Mario Blanco TAIS13

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "Digrafo.h"
#include <deque>

class sumidero {
private:
    std::vector<std::vector<bool>> g;
    std::vector<bool>visit;
    bool sumid;
    int vertice;
    void leeGrafo(int m) {
        for (int i = 0; i < m; ++i) {
            int a, b;
            std::cin >> a >> b;
            g[a][b] = true;
        }
    }
    void dfs(int origen) {
        
    }
public:
    
    sumidero(int n, int m) :g(n), visit(n),sumid(false){
        leeGrafo(m);
        for (int i = 0; !sumid&&i < n ; ++i) { //coste o(v)
            if () {//si su grado de salida es 0
                
            }
        }
    }
    void escribeSol() {
        if (sumid) std::cout << "SI " << vertice;
        else std::cout << "NO";
        std::cout << '\n';
    }
};

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int n, m;
    std::cin >> n >> m;
   if (!std::cin)  // fin de la entrada
      return false;
   sumidero t(n, m);
   t.escribeSol();
   
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
