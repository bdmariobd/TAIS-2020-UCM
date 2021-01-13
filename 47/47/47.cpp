
// Nombre y Apellidos Mario Blanco Dominguez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include "Matriz.h"

/*
    Recurrencia:

    zampar(i,j) es la maxima cantidad de comida que come nuestra vaca con los cubos de i a j y le toca

    caso base
    zampar(i,i) = comida[i] , la diagonal principal
    caso recursivo
    hay que probar a comer por la izquierda o por la derecha.

    zapar(i,j) = max comerizq , comerdcha

    comerizq(i,j) = comida[i] si i+1==j
                    comida[i] + mtx [i+2][j] si comida[i + 1] >= comida[j], ya que devoradora comera tambien por la izquierda
                    comida[i] + mtx[i+1][j-1] en caso contrario, devoradora comera por la derecha
                    
    comerdcha(i,j) = comida[j] si i+1==j
                    comida[j] + mtx[i][j - 2] si comida[j - 1] >= comida[i], ya que devoradora comera tambien por la derecha
                        comida[j] + mtx[i + 1][j - 1] en caso contrario, devoradora comera por la izquierda

*/

int zampar(const std::vector<int>& comida) {
    int n = comida.size();
    Matriz<int> mtx(n,n, 0);

    for (int i = 0; i < n; ++i) mtx[i][i] = comida[i];//caso base

    for (int d = 1; d < n; ++d) {
        for (int i = 0; i < n - d; ++i) {
            int j = i + d;
            int comerIzq, comerDcha;
            if (i + 1 == j) {
                comerIzq = comida[i];
                comerDcha = comida[j];
            }
            else {
                if (comida[i + 1] >= comida[j]) comerIzq = comida[i] + mtx[i + 2][j]; //devoradora comera tambien el de la izquierda
                else comerIzq = comida[i] + mtx[i + 1][j - 1];

                if (comida[j - 1] >= comida[i]) comerDcha = comida[j] + mtx[i][j - 2]; //devoradora comera tambien el de la derecha
                else comerDcha = comida[j] + mtx[i + 1][j - 1];
        
            }
            mtx[i][j] = std::max(comerIzq, comerDcha);

        }
    }

    return mtx[0][n - 1];

}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int N,cubo;
    std::cin >> N;
   if (N==0) 
      return false;
   std::vector<int> comida;

   while (N--) {
       std::cin >> cubo;
       comida.push_back(cubo);
   }
   std::cout << zampar(comida) << '\n';
     
   
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
