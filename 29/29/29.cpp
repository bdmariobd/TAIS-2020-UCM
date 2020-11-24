
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>
class hora {
private:
    int minutos;
    int horas;

public:
    hora(int h = 0, int m = 0) {
        horas = h;
        minutos = m;
    }
    bool operator<(hora const& h) const {
        return this->horas * 60 + this->minutos <
            h.horas * 60 + h.minutos;
    }
    bool operator<=(hora const& h) const {
        return this->horas * 60 + this->minutos  <=
            h.horas * 60 + h.minutos;
    }

    std::istream& operator>>(hora& h) {
        char aux;
        std::cin >> horas >>aux>> minutos;
        
    }
    hora operator+(int const& minutos) const {
        int mins, hor;
        mins = this->minutos + minutos;
        if (mins >= 60) {
            hor = this->horas + mins / 60;
            mins = mins % 60;
           
        }
        else return{ this->horas,mins };
        return{ hor,mins };
    }
};

class pelicula {
public:
    hora inicio, fin;
    int duracion;

    pelicula(hora inicio,hora fin,int duracion) {
        this->inicio = inicio;
        this->fin = fin;
        this->duracion = duracion;
    }

    bool operator<(pelicula const& other) const {
        return this->fin<other.fin;
    }
};
int caso(std::vector<pelicula> & pelis) {
    std::sort(pelis.begin(), pelis.end(), std::less<pelicula>());
    int vistas = 1;
    hora libre = pelis[0].fin +10;
    for (int i = 1; i < pelis.size(); ++i) {
        if (libre<=pelis[i].inicio) {
            ++vistas;
            libre = pelis[i].fin + 10;
        }
    }
    return vistas;

}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int n;
    std::cin >> n;
   if (n<=0)
      return false;
   std::vector<pelicula> pelis;
   int h,min;
   char aux;
   int duracion;
   for (int i = 0; i < n; i++) {
       std::cin >> h >>aux>>min>> duracion;
       hora ini (h, min);
       hora fin = ini + duracion;
       pelis.push_back({ini,fin,duracion});
   }
   std::cout << caso(pelis)<<'\n';
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
