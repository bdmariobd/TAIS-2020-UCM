#include <queue>
class ColaMedianas {
private:
	std::priority_queue<int, std::vector<int>, std::greater<int>> maximos;
	std::priority_queue<int, std::vector<int>,std::less<int>> minimos;

	void reordena() {
		if (maximos.size() == minimos.size()+1) { //quiero que el que sobre vaya a la de minimos
			minimos.push(maximos.top());
			maximos.pop();
		}
		else if (maximos.size()+2 == minimos.size()) { //si la cola de minimos es mucho mas grande que la de maximos
			maximos.push(minimos.top());
			minimos.pop();
		}
	}
public:
	void insertar(int x) {
		if (minimos.empty()) minimos.push(x);
		else {
			if (x > minimos.top()) maximos.push(x);
			else minimos.push(x);
		}
		reordena();
	}

	bool vacia() const {
		return minimos.empty();
	}
	
	int mediana() {
		if (vacia()) return -1;
		return minimos.top();
	}
	void quitarMediana() {
		if (vacia())return;
		minimos.pop();
		reordena();
	}
};

