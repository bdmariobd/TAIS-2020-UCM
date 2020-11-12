
// Nombre y Apellidos
//Mario Blanco TAIS13

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "Digrafo.h"
#include <deque>

class tareas {
private:
    Digrafo g;
    std::vector<bool>visit;
    std::deque<int> ordenTopolog;
    std::vector<bool>apilado;
    bool ciclo;
    void leeGrafo(int m) {
        for (int i = 0; i < m; ++i) {
            int a, b;
            std::cin >> a >> b;
            g.ponArista(a-1, b-1);
        }
    }
    void dfs(int origen) {
        apilado[origen] = true;
        visit[origen] = true;
        for (int w : g.ady(origen)) {
            if (ciclo) return;
            if (!visit[w]) dfs(w);
            else if (apilado[w]) ciclo = true;
        }
        ordenTopolog.push_front(origen);
        apilado[origen] = false;
    }
public:
    
    tareas(int n, int m) :g(n),ciclo(false), visit(n), ordenTopolog(0),apilado(n){
        leeGrafo(m);
        for (int i = 0; i < n; ++i) {
            if (!visit[i]) dfs(i);
        }
    }
    void escribeSol() {
        if (ciclo) std::cout << "Imposible";
        else for (int i : ordenTopolog)std::cout << i+1 << " ";
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
   tareas t(n, m);
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
