#include <iostream>
#include <vector>
using namespace std;

vector<int> A[100001]; // listas de adyacencia, tamaño 100000+1

int main() {
	int c;
	cin >> c;
	while(c > 0) {
		int n; // numero de nodos
		cin >> n;

		for(int i = 0; i < n; ++i) {
			// leo el camarada
			int camar;
			cin >> camar;
			// voy leyendo sus adyacentes y los pusheo en el vector
			int adj;
			while(cin >> adj and adj != '\n') {
				A[camar].push_back(adj);
			}
		}

		for(int i = 0; i < n; ++i) {
			cout << i << " ";
			for(unsigned int j = 0; j < A[i].size(); ++j) {
				cout << A[i][j] << " ";
			}
			cout << endl;
		}
		--c;
	}
}