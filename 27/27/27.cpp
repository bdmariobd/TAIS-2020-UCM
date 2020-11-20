
// Nombre y Apellidos Mario Blanco

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include<vector>

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

unsigned int parches(const std::vector<unsigned int>& agujeros, int l) {
    unsigned int parches = 1;//parche puesto para el primer agujero. ¿Llegara para el 2º?
    int longCubierta = l;
    for (int i = 0; i < agujeros.size()-1; ++i) {
        if (agujeros[i] != agujeros[i+1]) {//agujero en 2 pos distintas
            if (agujeros[i + 1] - agujeros[i] <= longCubierta) {//el parche puesto para i llega para i+1 y puede que para mas
                longCubierta -= agujeros[i + 1] - agujeros[i];
            }
            else {
                longCubierta = l;
                ++parches;
            }
        }
    }
    return parches;
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int n, l;
    unsigned int aux;
    std::cin >> n >> l;
   if (!std::cin)  // fin de la entrada
      return false;
   std::vector<unsigned int> agujeros;
   while (n--) {
       std::cin >> aux;
       agujeros.push_back(aux);
   }
   std::cout << parches(agujeros, l) << '\n';
   
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
