
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <string>

/*
    palindromo(i,j) devuelve el menor nº de letras posible a añadir a la palabra desde la casilla i a la j

    caso base
    i=j -> palindromo(i,j) =0
    caso recursivo

    palabra[i]=palabra[j] -> palindromo(i,j) = palindromo(i+1,j-1)

    palabra[i]!=palabra[j] -> palindromo(i,j) = min (palidromo() , palindromo()  )
*/
int palindromo(const std::string& palabra, int i, int j, Matriz<int>& mtx) {

}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    std::string palabra;
    std::cin >> palabra;
   if (!std::cin)  // fin de la entrada
      return false;
   int tam = palabra.size();
   
   
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
