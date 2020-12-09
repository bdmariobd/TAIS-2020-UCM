
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include<vector>
struct cuerda {
    int l, coste;
};
int64_t formas(int l, const std::vector<cuerda>& cuerdas) {
    //std::vector<int64_t> v(l + 1, 0);
    std::vector<std::vector<int64_t>> v(cuerdas.size()+1, std::vector<int64_t>(l+1,0));
    int64_t longAct = 0;
    for (int i = 1; i <= cuerdas.size(); ++i) {
        longAct += cuerdas[i - 1].l;
        for(int j=1;j<=l;++j){
        //for (int j = l; j >0; --j) {
            if (longAct == j)
                //v[j] = v[j] + v[j - cuerdas[i - 1].l] +1;
                v[i][j] += v[i-1][j]+1;
        }
    }
    //return v[l];
    return v[cuerdas.size()-1][l];
}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    int n, l, lo, cost;
    std::cin >> n >> l;
   if (!std::cin)  // fin de la entrada
      return false;
   std::vector<cuerda> cuerdas;
   while (n--) {
       std::cin >> lo >> cost;
       cuerdas.push_back({ lo,cost });
   }
   
   auto nFormas = formas(l, cuerdas);

   if (nFormas == 0) {
       std::cout << "NO\n";
   }
   else {
       std::cout << nFormas << '\n';
   }
   
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
