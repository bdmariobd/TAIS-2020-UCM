
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <vector>
#include<algorithm>
#include "EnterosInf.h"


/*
    monedas(i,j) debe ser la cantidad minima de monedas para pagar la cantidad j usando las monedas de i a 1. 
    caso base: monedas(i,0) = 0 // no neesito monedas
               monedas(0,j) = infinito // no puedo pagarlo
    caso recursivo:  monedas(i-1,j), si cantidad i<0 o valor[i] >j
                     min (   min (monedas i-1, j - x * valor[i]) + x) , monedas(i-1,j)) en caso contrario
                       ES DECIR: uso una cantidad minima de 0 a x monedas de la moneda i , puediendo usar como mucho el nº de monedas i que tengo en total, o lo que tengo pendiente por pagar entre lo que vale esa moneda
                                
*/

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


EntInf resolver(const std::vector<std::pair<int, int>> &datos , const int costeTotal){
    Matriz<EntInf> mtz(datos.size() + 1, costeTotal + 1, Infinito);
    mtz[0][0] = 0;
    for (int i = 1; i < datos.size() + 1; ++i) {
        mtz[i][0] = 0;
        for (int j = 1; j < costeTotal + 1; ++j) {
            EntInf aux = Infinito;
            int cantAUsar = std::min(j / datos[i-1].first, datos[i-1].second); 
            //de la moneda i quiero usar la minima cantidad posible, que como mucho sera: o el nº de monedas i que tengo en total, o lo que tengo pendiente por pagar entre lo que vale esa moneda
            for (int x = 0; x <= cantAUsar; x++) {
                //ahora en bucle, sabiendo que puedo gastar como mucho cantAUsar monedas del tipo i, tengo que comprobar la minima cantidad de 0 a x monedas a usar de la moneda i
				aux = std::min(aux, mtz[i-1][j - (x * datos[i-1].first)] + x);
				mtz[i][j] = aux;
			}
        }
    }
    return mtz[datos.size()][costeTotal];
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int N;
    std::cin >> N;
   if (!std::cin)  // fin de la entrada
      return false;
   std::vector<std::pair<int, int>> monedas; //valor, cantidad
   int valor, cantidad;
   for (int i = 0; i < N; ++i) {
       std::cin >> valor;
       monedas.push_back({ valor,0 });
   }
   for (int i = 0; i < N; ++i) {
       std::cin >> cantidad;
       monedas[i].second = cantidad;
   }
   int costeTotal;
   std::cin >> costeTotal;

   auto result = resolver(monedas, costeTotal);

   if (result == Infinito) std::cout << "NO\n";
   else std::cout << "SI " << result << '\n';
   
   
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
