
// Nombre y Apellidos
//Mario Blanco Dominguez

#include <iostream>
#include <fstream>
#include<queue>

//Guarda la id, el periodo, y espera va acumulando los periodos
struct usuario {
    int id,per, espera;
};

//Es necesario crear el operador menor, pero como es una cola de minimos y no de maximos los utilizo al reves
bool operator<(const usuario& u2, const usuario& u1) {
    return u1.espera < u2.espera ||
        (u1.espera == u2.espera && u1.id < u2.id);
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() { //O(n log(n)) + O(envios log(n))
   
   // leer los datos de la entrada
    int n,id,per,envios;
    std::cin >> n;
   if (n==0)
      return false;
   std::priority_queue<usuario> cola;
   
   for (int i = 0; i < n; ++i) {  //O(n log(n))
       std::cin >> id>>per;
       cola.push({ id,per, per }); //O(log(n))
   }
   std::cin >> envios;
   /*
   * El usuario al que envian es el mas prioritario de la cola. Lo escribo, lo expulso de la cola, le incremento
   * su espera para siguientes periodos y lo vuelvo a introducir en la cola
   */
   while (envios > 0) {//O(envios log(n))
       usuario u = cola.top();
       cola.pop();//O(log(n))
       u.espera += u.per;
       std::cout << u.id << "\n";
       cola.push(u);//O(log(n))
       --envios;
   }
   std::cout << "---\n";
   return true;
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("datos.txt");
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
