
// Nombre y Apellidos Mario Blanco

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>

#include "Matriz.h"

struct tesoro {
    int profundidad, oro;
};

/*
    botin(i,j) = maximo oro que podemos recoger con j de oxigeno considerando los tesoros de 1 a i
    Casos basicos
    botin(0,j) =0
    botin(i,0)=0

    botin (i,j) = botin(i-1,j) si 3pi>j
                  max (botin(i-1,j) , botin (i-1 , j-3pi) + vi) su 3pi<=j


*/

int botin(std::vector<tesoro> const& obj, int i, int j, Matriz<int>& recogidos) {//version dinamica descendente
    if (recogidos[i][j] != -1) return recogidos[i][j];
    if (i == 0 || j == 0) recogidos[i][j] = 0;
    else if (obj[i - 1].profundidad * 3 > j) recogidos[i][j] = botin(obj, i - 1, j, recogidos);
    else recogidos[i][j] = std::max(botin(obj, i - 1, j, recogidos),
        botin(obj, i - 1, j - obj[i - 1].profundidad * 3, recogidos) + obj[i - 1].oro);
    return recogidos[i][j];
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int T;
    std::cin >> T;
   if (!std::cin)  // fin de la entrada
      return false;
   int n;
   std::cin >> n;
   std::vector<tesoro> objetos;
   while (n--) {
       int prof, oro;
       std::cin >> prof >> oro;
       objetos.push_back({ prof,oro });
   }
   
   Matriz<int> recogidos(objetos.size() + 1, T + 1, -1);
   int oro_conseguido = botin(objetos, objetos.size(), T, recogidos);
   int i = objetos.size();
   int cont = 0;
   std::vector<bool> cogidos(i, false);
   while (i > 0 && T > 0) {
       if (recogidos[i][T] != recogidos[i - 1][T]) {
           ++cont;
           cogidos[i - 1] = true;
           T -= objetos[i - 1].profundidad * 3;
       }
       --i;
   }
   
   std::cout << oro_conseguido << '\n' << cont<<'\n';
   for (int i = 0; i < cogidos.size();++i) {
       if (cogidos[i]) std::cout << objetos[i].profundidad << " " << objetos[i].oro << '\n';
   }
   std::cout << "---\n";
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
