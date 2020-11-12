
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include<queue>



// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int n;
    long long int valor;
    std::cin >> n;
   if (n==0)
      return false;
   std::priority_queue<long long int,std::vector<long long int>,std::greater<long long int>> cola;
   for (int i = 0; i < n; ++i) { //O(n log(n))
        std::cin >> valor;
        cola.push(valor);
   }
   long long int primer;
   long long int esfuerzo = 0, suma = 0;
   while (cola.size()>1) { // O(nlog(n))
       primer = cola.top();
       cola.pop();
       suma = primer + cola.top();
       cola.pop();
       esfuerzo += suma;
       cola.push(suma);     
   }

   std::cout << esfuerzo << "\n";


   
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
