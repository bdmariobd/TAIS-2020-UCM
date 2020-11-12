
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>

struct paciente {
    int g,orden;
    std::string nombre;
};

bool operator<(const paciente& p1, const paciente& p2) {
    return p1.g < p2.g || (p1.g == p2.g && p1.orden > p2.orden);
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int n;
    std::cin >> n;
   if (n==0)
      return false;
   char accion;
   std::string nombre;
   int g;

   std::priority_queue<paciente> cola;
   for (int i = 0; i < n; ++i) {
       std::cin >> accion;
       if (accion == 'A') {
           std::cout << cola.top().nombre<<'\n';
           cola.pop();  //O(log(n))
       }
       else { //accion I
           std::cin >> nombre >> g;
           cola.push({ g,i,nombre });//O(log(n))
       }
   }
   std::cout << "---\n";
   
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
