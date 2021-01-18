
// Nombre y Apellidos
//Mario Blanco Dominguez

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>
#include<algorithm>


struct cancion {
    int duracion, puntuacion;

    bool operator < (const cancion& c) const{
        return (puntuacion/(double)duracion > c.puntuacion/(double)c.duracion);
    }
};

struct Nodo {
    //std::vector<bool> sol;
    int k;
    int duracionA, duracionB; // duracion acumulada
    int puntuacion; // puntuacion acumulada
    double puntuacion_est; // prioridad
    bool operator<(Nodo const& otro) const {
        return otro.puntuacion_est > puntuacion_est;
    }
};

double estimar(const std::vector<cancion>& canciones, int tamCara, const Nodo & x) {
    double hueco = (double) 2*tamCara - x.duracionA - x.duracionB , estimacion = x.puntuacion;
    int i = x.k + 1;
    while (i < canciones.size() && canciones[i].duracion < hueco) {
        hueco -= canciones[i].duracion;
        estimacion += canciones[i].puntuacion;
        ++i;
    }

    if (i < canciones.size()) estimacion += (hueco / canciones[i].duracion) * canciones[i].puntuacion;

    return estimacion;

}
void resolver(const std::vector<cancion>& canciones, int tamCara, int& mayorPunt) {
    int n = canciones.size();
    Nodo y;
    y.k = -1;
    y.duracionA = y.duracionB = y.puntuacion = 0;
    y.puntuacion_est = estimar(canciones, tamCara, y);
    std::priority_queue<Nodo> cola;
    cola.push(y);
    mayorPunt = -1;

    while (!cola.empty() && cola.top().puntuacion_est > mayorPunt) {
        y = cola.top();
        cola.pop();
        Nodo x(y);
        ++x.k;
        if (y.duracionA + canciones[x.k].duracion <= tamCara) {//meto cara a
            x.duracionA = y.duracionA + canciones[x.k].duracion;
            x.puntuacion = y.puntuacion + canciones[x.k].puntuacion;
            //puntuacionEstimada??
            //es prometedor??
            if (x.k == n - 1) {
                mayorPunt = x.puntuacion;
            }
            else cola.push(x);
        }
        x.duracionA = y.duracionA;
        if (y.duracionB + canciones[x.k].duracion <= tamCara) {//meto cara b
            x.duracionB = y.duracionB + canciones[x.k].duracion;
            x.puntuacion = y.puntuacion + canciones[x.k].puntuacion;
            //puntuacionEstimada??
            //es prometedor??
            if (x.k == n - 1) {
                mayorPunt = x.puntuacion;
            }
            else cola.push(x);
        }

        //no meto
        x.duracionB = y.duracionB;
        x.puntuacion = y.puntuacion;
        x.puntuacion_est = estimar(canciones, tamCara, x);
        
        if (x.puntuacion_est > mayorPunt) {
            if (x.k == n - 1) {
                mayorPunt = x.puntuacion;
            }
            else cola.push(x);
        }     

    }
}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   // leer los datos de la entrada
    int N,dur,punt,tamCara,sol;
    std::cin >> N;
   if (N==0)
      return false;
   std::cin >> tamCara;
   std::vector<cancion> canciones;
   while (N--) {
       std::cin >> dur >> punt;
       canciones.push_back({ dur,punt });
   }
   
   std::sort(canciones.begin(), canciones.end());
   // escribir sol
   resolver(canciones,tamCara,sol);
   std::cout << sol << '\n';
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
