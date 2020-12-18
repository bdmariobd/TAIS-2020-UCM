
// Nombre y Apellidos Mario Blanco

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>
#include<queue>

struct tarea
{
    int ini, fin;
};
bool operator<(const tarea& t1, const tarea& t2) {
    return t1.ini < t2.ini;
}
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int n,ini,fin;
    std::cin >> n;
   if (n==0)
      return false;
   std::vector<tarea> tareas;
   while (n--) {
       std::cin >> ini >> fin;
       tareas.push_back({ ini,fin });
   }
   std::sort(tareas.begin(), tareas.end());
   std::priority_queue<int,std::vector<int>, std::greater<int>> libres;
   //int compañeros = 0;
   libres.push(tareas[0].fin);
   // escribir sol
   for (int i = 1; i < tareas.size(); ++i) {
       if (tareas[i].ini >= libres.top()) { //la puede hacer alguien, no necesitamos otro
           libres.pop();
           libres.push(tareas[i].fin);
       }
       else {//necesitamos otro
           libres.push(tareas[i].fin);
       }
   }
   std::cout << libres.size() - 1 << '\n';
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
