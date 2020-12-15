
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <string>

/*
    palindromo(i,j) devuelve el menor nº de letras posible a añadir a la palabra desde la casilla i a la j

    caso base
    i=j -> palindromo(i,j) =0
    caso recursivo

    palabra[i]=palabra[j] -> palindromo(i,j) = palindromo(i+1,j-1)

    palabra[i]!=palabra[j] -> palindromo(i,j) = min (palidromo(i, j-1)+1 , palindromo(i+1, j)+1  )
*/
void reconstruir(const std::string& palabra, int i, int j, const Matriz<int>& mtx, std::string&sol) {
    //std::string sol="";
    if (i > j) return;
    if (i == j) sol.push_back(palabra[i]);
    
    else if (palabra[i] == palabra[j]) {
        sol.push_back(palabra[i]);
        reconstruir(palabra, i + 1, j - 1,  mtx,sol);
        sol.push_back(palabra[j]);
    }
    else {
        if (mtx[i][j] == mtx[i][j-1] + 1) { //quitar la j consigue un mejor resultado
            sol.push_back(palabra[j]);
            reconstruir(palabra, i , j - 1, mtx,sol);
            sol.push_back(palabra[j]);
        }
        else { //quitar la i consigue un mejor resultado
            sol.push_back(palabra[i]);
            reconstruir(palabra, i+1, j, mtx,sol);
            sol.push_back(palabra[i]);
        }
    }
   
}
int palindromo(const std::string& palabra, int i, int j, Matriz<int>& mtx) {
    if (mtx[i][j] != -1) return mtx[i][j];
    else {
        if (i == j) mtx[i][j] = 0;
        else {
            if (palabra[i] == palabra[j]) mtx[i][j] = palindromo(palabra, i + 1, j - 1, mtx);
            else mtx[i][j] = std::min(palindromo(palabra, i, j - 1,mtx) + 1, palindromo(palabra, i + 1, j,mtx) + 1);
        }
        return mtx[i][j];
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
   // leer los datos de la entrada
    std::string palabra;
    std::cin >> palabra;
   if (!std::cin)  // fin de la entrada
      return false;
   int tam = palabra.size();
   Matriz<int> mtx(tam, tam, -1);

   int num = palindromo(palabra, 0, tam-1, mtx);
   std::string sol = "";
   reconstruir(palabra, 0, tam - 1, mtx, sol);
   std::cout << num<<" "<<sol<<'\n';
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
