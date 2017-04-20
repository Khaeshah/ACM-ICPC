#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i) {
		int x,y;
		cin >> x >> y;

		// Cambio variable para evitar valores negativos
		if(y > x) {
			int aux;
			aux = y;
			y = x;
			x = aux;
		}
		int diff = x-y;

		// El numero existira si su diferencia es 0 o 2
		if (diff == 0 or diff == 2) {
			// Caso dos pares
			if(x%2 == 0 and y%2 == 0) cout << x+y << endl;
			// Caso dos impares
			else if(x%2 != 0 and y%2 != 0) cout << x+y-1 << endl;
		}
		else cout << "No Number" << endl;
	}
}