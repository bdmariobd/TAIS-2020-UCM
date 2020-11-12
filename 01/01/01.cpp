
// Nombre y Apellidos
/*
* GRUPO 11
1
Mario Blanco Domínguez
TAIS13
2
Javier Ignacio Sotelino Barriga
TAIS77
3
Francisco Boccassi
TAIS14
4
Alberto Chaves
TAIS22

*/


#include <iostream>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema
// 1st bool devuelve si cumple la condicion AVL
//2nd es un par, que devuelve como 1er int la altura acumulada, 
//y como segundo devuelve otro par con el minimo y maximo encontrado 
//en los arboles hijos, para comprobar si es de busqueda

std::pair<bool,std::pair<int,std::pair<int,int>>> resolverArbol(bintree<int> v) {
    if (v.empty()) return { true,{0,{-1,-1}} }; //si es vacio, cumple AVL y altura 0
    auto izq = resolverArbol(v.left()), dcha = resolverArbol(v.right());

    bool hoja = v.left().empty() && v.right().empty();

    int min = izq.second.second.first == -1 ? v.root() : izq.second.second.first;
    int max = dcha.second.second.second == -1 ? v.root() : dcha.second.second.second;

    bool cumple = (izq.first && dcha.first) //que sus hijos sean AVL tambien
        && (std::abs(izq.second.first - dcha.second.first) <= 1) //que la diferencia de alturas sea como mucho 1
        && (hoja ? // comprueba que es de busqueda. Si es nodo hoja, es de busqueda
            true :
            (izq.second.second.first == -1 || izq.second.second.second < v.root()) && //en el nodo izquierdo comprueba que el mayor encontrado ahi sea menor que la raiz actual
            (dcha.second.second.first == -1 || dcha.second.second.first > v.root()));//en el nodo derecho comprueba que el menor encontrado ahi sea mayor que la raiz actual
            //si es -1, no compruebo, ya que significa que el hijo era arbol vacio

            return { cumple,{std::max(izq.second.first,dcha.second.first) + 1,{min,max} } };
    //devuelvo si cumple la condicion, devuelvo la altura y la raiz del arbol actual
}
bool resolver(bintree<int> v) {
    return resolverArbol(v).first;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
   // leer los datos de la entrada
    if (resolver(leerArbol(-1))) std::cout << "SI\n";
    else std::cout << "NO\n";
   
   // escribir solución
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
