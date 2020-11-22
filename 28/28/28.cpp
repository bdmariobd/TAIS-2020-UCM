
// Nombre y Apellidos
//Mario Blanco
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int soldados(std::vector<int>& ataque, std::vector<int>& defensa) {
    std::sort(ataque.begin(),ataque.end(), std::less<int>());
    std::sort(defensa.begin(), defensa.end(), std::less<int>());
    int exitos = 0, i=0,j=0, n=ataque.size();//i ataque ||  j defensa
    while(i<n && j<n) {
        if (defensa[j] >= ataque[i]) {
            ++exitos;
            ++i; //si consigo defender el ataque avanzo. 
            //Se puede demostrar que, estando los dos vectores ordenados, puedo recorrer mis defensas intentando defender, que
            //todas mis defensas anteriores no van a poder defender otros ataque siguientes
        }

        ++j;
    }
    return exitos;

}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int n,aux;
    std::cin >> n;
   if (!std::cin)  // fin de la entrada
      return false;
   std::vector<int>ataque, defensa;
   for (int i = 0; i < n; ++i) {
       std::cin >> aux;
       ataque.push_back(aux);
   }
   for (int i = 0; i < n; ++i) {
       std::cin >> aux;
       defensa.push_back(aux);
   }
   std::cout << soldados(ataque,defensa)<<'\n';
   
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
