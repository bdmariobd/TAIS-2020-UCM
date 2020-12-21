
// Nombre y Apellidos Mario Blanco

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include<string>
#include "Matriz.h"

/*
    RECURRENCIA

    A(i,j)= se puede obtener a desde xi a xj
    (lo mismo b y c)

    base : 
        A(i,i) = secuencia[i] es 'a'
        (lo mismo b y c)

    recursivo :
        A(i,j) = 
        (A(i,k) && C(k + 1,j) ||
        (B(i,k) && C(k + 1,j) ||
        (C(i,k) && A(k + 1,j) siendo i<=k<j

    Lo mismo ocurre con B (aa,ab y bb) y con C (ba,cb y cc)

    Problema resuelto con el recorrido por diagonales
*/

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    std::string secuencia;
    std::cin >> secuencia;
   if (!std::cin)  // fin de la entrada
      return false;
   int tam = secuencia.size();
   Matriz<bool> mA(tam+1, tam +1);
   Matriz<bool> mB(tam +1 , tam +1);
   Matriz<bool> mC(tam+1, tam +1);
   
   for (int i = 1; i <= tam; ++i) {
       mA[i][i] = secuencia[i-1] == 'a';
       mB[i][i] = secuencia[i-1] == 'b';
       mC[i][i] = secuencia[i-1] == 'c';
   }

   for (int d = 1; d < tam; ++d) {
       for (int i = 1; i <= tam - d; ++i) {
           int j = i + d;
           mA[i][j] = false;
           for (int k = i; k < j && !mA[i][j]; ++k)
               mA[i][j] = (mA[i][k] && mC[k + 1][j]) || (mB[i][k] && mC[k + 1][j]) || (mC[i][k] && mA[k + 1][j]);
           mB[i][j] = false;
           for (int k = i; k < j && !mB[i][j]; ++k)
               mB[i][j] = (mA[i][k] && mA[k + 1][j]) || (mA[i][k] && mB[k + 1][j]) || (mB[i][k] && mB[k + 1][j]);
           mC[i][j] = false;
           for (int k = i; k < j && !mC[i][j]; ++k)
               mC[i][j] = (mB[i][k] && mA[k + 1][j]) || (mC[i][k] && mB[k + 1][j]) || (mC[i][k] && mC[k + 1][j]);
       }
   }

   if (mA[1][tam]) std::cout << "SI\n";
   else std::cout << "NO\n";
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
