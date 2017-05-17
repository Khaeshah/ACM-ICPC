#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main() {
	// 3 <= n <= 30
	// maximo 60 cells de tablero
	/*
	0 = 0;
	1 = 1 (una azul)
	2 = 3 (dos azules + 1 azul)
	3 = 3 (dos azules + 1 azul)
	4 = dos azules + dos azules 
		(para cada dos azules, sumo dos soluciones)
	5 = 12 (dos azules + dos azules))
	*/
	int T;
	cin >> T;

	vector<int> res(31);
	res[0] = 0;
	res[1] = 1;
	res[2] = 3;
	// Genero los resultados
	for(int i = 3; i <= 30; ++i) {
		res[i] = res[i-2]* 2 + res[i-1];
	}
	while(T--) {
		int n;
		cin >> n;
		int solucion;
		for(int i = 3; i <= 30; ++i) {
			if(i % 2 == 0) {
				// Si estamos mirando un caso par
				solucion = (2*res[(i-2)/ 2] + res[i / 2]);
				cout << "Solucion vale " << solucion << endl;
			}
			else if(i % 2 != 0) {
				// Si estamos mirando un caso impar
				solucion = res[(i-1) / 2];
				cout << "Solucion vale " << solucion << endl;
			}
		}
		cout << solucion << endl;
	}
}


		/*int n;
		cin >> n;
		float solucion = 0;

		if (n >= 2) {
			if(n % 2 == 0) {
				// caso par
				solucion = (n / 2) * n;
			}
			else {
				// caso impar
				solucion = ceil(n / 2.0)+1;
				cout << "El ceil vale " <<  ceil(n / 2.0) * n << endl;
			}
			cout << solucion << endl;
		}
		else if(n == 1) cout << 1 << endl;
		else cout << 0 << endl;*/