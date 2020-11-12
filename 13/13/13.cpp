
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>


#include "Grafo.h" // propios o los de las estructuras de datos de clase

class guardias {
private:
    Grafo g;
    std::vector<bool> visit;
    std::vector<bool>hayguardia;
    int total,guard,noguard;
    bool posible;
    //std::vector<int>ant;

    void leeGrafo(int a) {
        int p1, p2;
        for (int i = 0; i < a; ++i) {
            std::cin >> p1 >> p2;
            p1--; p2--;
            g.ponArista(p1, p2);
        }
    }
    void dfs(int v) { //el coste es de O(v+a)
        visit[v] = true;
        for (int w : g.ady(v)) {
            if (!visit[w]) {
                if (!hayguardia[v]) {
                    hayguardia[w] = true;
                    ++guard;
                }
                else {
                    hayguardia[w] = false;
                    ++noguard;
                }
                dfs(w);
            }
            else if (hayguardia[v] == hayguardia[w]) posible = false;

        }
    }
    void recorreConexas() {
        for (int i = 0; i < g.V(); ++i) {
            if (!visit[i]) {
                hayguardia[i] = true;
                dfs(i);
                total += std::min(guard, noguard);
                guard = 1; noguard = 0;
            }
        }
    }
public:
    guardias(int v, int a):g(v), visit(g.V()) , hayguardia(g.V()), total(0),guard(1),noguard(0),posible(1){
        leeGrafo(a);
        recorreConexas();
    }
    int minGuardias() {
        return posible ? total : -1;
    }
     
};
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int v, a;
    std::cin >> v;
   if (!std::cin)  // fin de la entrada
      return false;
   std::cin >> a;
   guardias g(v, a);
   int sol = g.minGuardias();
   if (sol == -1)std::cout << "IMPOSIBLE\n";
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
