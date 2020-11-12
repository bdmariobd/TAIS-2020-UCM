
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "Grafo.h"

class Problema {
private:
    std::vector<std::vector<char>> g;
    int filas, columnas;
    std::vector<std::vector<bool>> visit;
    void leerImagen() {
        for(int i=0;i<filas;++i)
            for (int j = 0; j < columnas; ++j) {
                char c;
                std::cin >> c;
                g[i][j] = c;
            }
                
    }
    std::vector<std::pair<int, int>> direcciones = { {0,1},{0,-1},{1,0},{-1,0} };
    bool posValida(int f, int c) {
        return f >= 0 && c >= 0 && f < filas&& c < columnas;
    }
    int dfs(int f, int c) {
        visit[f][c] = true;
        int negros = 1;
        for (auto dir: direcciones) {
            if (posValida(f+dir.first, c+dir.second) && g[f + dir.first][c + dir.second] == '#' && !visit[f + dir.first][c + dir.second]) {
                negros += dfs(f + dir.first,c + dir.second);
            }
        }
        return negros;
    }
public:
    Problema(int f, int c) :g(f,std::vector<char>(c)), visit(f, std::vector<bool>(c)), filas(f), columnas(c) {
        leerImagen();
    }
    //1st nºmanchas, 2nd mancha mayor
    std::pair<int, int> mayorMancha() {
        int mayor = 0, cont=0;
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                if (!visit[i][j] && g[i][j] == '#') {//si no fue visitado y es negro, visito esta mancha negra
                    ++cont;
                    mayor = std::max(mayor, dfs(i, j));
                }
            }
            
        }
        return {cont,mayor};
    }
};
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int f, c;
    std::cin >> f >> c;
   if (!std::cin)  // fin de la entrada
      return false;
   Problema p(f, c) ;
   auto sol = p.mayorMancha();
   std::cout << sol.first << " " << sol.second << '\n';
   
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
