#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
// función que resuelve el problema

struct tarea {
    int ini, fin,p;
};

bool operator<(const tarea& t2, const tarea& t1) {
    return t1.ini < t2.ini || (t1.ini == t2.ini) && (t1.fin < t2.fin);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int Nu, Np, T;
    cin >> Nu;
    if (!std::cin)
        return false;
    cin>> Np >> T;
    priority_queue<tarea> colita;
    for (int i = 0; i < Nu ; i++) {
        int ini, fin;
        cin >> ini >> fin;
        colita.push({ ini,fin,0});
    }
    for (int i = 0; i < Np; i++) {
        int ini, fin,periodo;
        cin >> ini >> fin>>periodo;
        colita.push({ ini,fin,periodo});
    }
    int tActual=0;
    bool superpuesta=false;
    while (colita.top().ini < T && !superpuesta && colita.size() > 1) {
        tarea aux = colita.top();
        colita.pop();
        if (aux.fin > colita.top().ini && colita.top().ini<T) superpuesta = true;
        if (aux.p != 0) {
            aux.ini += aux.p;
            aux.fin += aux.p;
            // a la cola, pepsi cola
            colita.push(aux);
        }
        tActual = aux.fin;
    }
    if (superpuesta) cout << "SI" << " \n";
    else cout << "NO\n";
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}