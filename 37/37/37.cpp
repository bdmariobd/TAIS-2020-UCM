
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include<vector>
#include "Matriz.h"

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...



// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int n;
    std::cin >> n;
   if (!std::cin)  // fin de la entrada
      return false;
  
   Matriz<int> mtx(n, n, 0);
   // lectura de los datos.
   for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            std::cin >> mtx[i][j];
   // Optimizando espacio, sustituiremos en los valores de la matriz la suma de los nuevos valores, 
   // es decir el valor que estaba más el máximo de su fila anterior, resultando que no habria coste en espacio adicional
   //(aunque en un hipotetico caso de que no se pudiese modificar la matriz original, el coste adicional seria O(n^2))

   //tablero(i,j)
   for (int i = 1; i < n; i++) {
       for (int j = 0; j < n; j++) {
           // 3 casos, 2 dónde me salgo de la tabla, 1 dónde puedo ir a ambos 3 lados.
           if (j == 0) { //no se puede mirar a la izq
               mtx[i][j] += std::max(mtx[i - 1][j], mtx[i - 1][j + 1]);
               // Actualizo mi posición ij seleccionando el máximo con la fila de abajo, al centro y a la derecha.
           }
           else if (j == n - 1) {//no se puede mirar a la derecha
               mtx[i][j] += std::max(mtx[i - 1][j], mtx[i - 1][j - 1]);
               // Actualizo mi posición ij seleccionado el máximo con la fila de abajo, al centro y a la izquierda.
           }
           else {//se puede mirar a todos los lados
               mtx[i][j] += std::max(std::max (mtx[i - 1][j - 1], mtx[i - 1][j + 1]),mtx[i-1][j]);
           }
       }
   }
   // Para obtener el máximo valor y su indice, puesto que vamos sumando en la última fila, buscamos en la última fila.
   // Empezando en el primer indice de la última fila, y desde la j=0;
   int max_value = mtx[n-1][0], max_pos = 0;
   for (int j = 1; j < n; ++j) {
       //Recorro toda la fila comparando con el valor auxiliar max_value, si es mayor, actualizo y sigo, lo mismo hago con la pos;
       if (mtx[n - 1][j] > max_value) {
           max_pos = j;
           max_value = mtx[n - 1][j];
       }
   } // Sumo 1 porque empiezo en 0 ->
   std::cout << max_value << " " << max_pos +1 << '\n';   
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
