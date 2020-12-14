#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Matriz.h"

using namespace std;

/*
subsecuencia(i,j) : nº caracteres de la secuencia más larga.
caso base:
subsecuencia (0,j )=0 <- para todo j
subsecuencia(i,0) =0 <- para todo i

caso recursivo :
subsecuencia(i,j) = subsecuencia(i-1,j-1) +1  si palabra1[i -1] =palabra2[j -1]
subsecuencia(i,j) max(subsecuencia(i-1,j),(subsecuencia(i,j-1))   si palabra1[i - 1] != palabra2[j - 1]
*/

bool resuelveCaso() {

	string p1, p2;
	cin >> p1;
	if (!std::cin) return false;
	cin >> p2;
	Matriz<int> tabla(p1.size() + 1, p2.size() + 1, 0);
	int t1, t2;
	t1 = p1.length();
	t2 = p2.length();
	for (int i = 1; i <= t1; i++) {
		for (int j = 1; j <= t2; j++) {
			if (p1[i - 1] == p2[j - 1]) {
				tabla[i][j] = tabla[i - 1][j - 1] + 1;
			}
			else {
				tabla[i][j] = std::max(tabla[i - 1][j], tabla[i][j - 1]);
			}
		}
	}
	int tamSubsec = tabla[t1][t2];
	string sol(tamSubsec, ' ');
	while (tamSubsec > 0) {
		if (p1[t1 - 1] == p2[t2 - 1]) {
			--tamSubsec;
			--t1; --t2;
			sol[tamSubsec] = p1[t1];
		}
		else {
			if (tabla[t1][t2] == tabla[t1][t2 - 1]) --t2;
			else --t1;

		}

	}
	//reverse(sol.begin(), sol.end());
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