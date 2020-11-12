
// Nombre y Apellidos
//Mario Blanco Domínguez
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>



struct cliente {
    int tiempo, caja;
};

bool operator<(const cliente& c2, const cliente& c1) {
    return c1.tiempo < c2.tiempo || (c1.tiempo == c2.tiempo) && c1.caja < c2.caja;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

/*
    Para gestionar la caja, meto clientes(ordenado por tiempo, tambien guardo su caja)
    Se insertan clientes. Si la cola esta vacia, va a la primera caja. Si hay clientes, 
    se mete en la caja tamaño cola +1 . En caso de estar todas las cajas ocupadas, hay que
    sacar al cliente mas prioritario(menor tiempo) e insertar al siguiente cliente en su 
    misma caja.

    Cuando solo queda Ismael, nuestro sujeto, se mete en la caja size+1, y si esta llena en la caja
    del que va a abandonar.

*/
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int n, c;
    std::cin >> n >> c;
   if (n==0)
      return false;
   std::priority_queue<cliente> cola;
   //std::queue<cliente> cola;
   int tCliente;
   for (int i = 0; i < c; ++i) { //coste n log n siendo n el num de clientes
       std::cin >> tCliente;
       if (cola.size() < n) {
           int tam = cola.size() +1;
           cola.push({ tCliente,tam});
       }
       else {
           int caja = cola.top().caja;
           tCliente += cola.top().tiempo;
           cola.pop();
           cola.push({ tCliente,caja });
       }
   }
   // escribir sol

   if (cola.size() < n) {
       std::cout << cola.size()+1 << '\n';
   }
   else std::cout << cola.top().caja << '\n';
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
