#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A[100001];

int BFS(int s, int t) {
	// BFS Notebook
	if(s == t) return 0;
	int cola[100001], k = 0;  // inicializar cola cola = l
	vector<int> vDist(N, -1); // inicializar distancias a -1
	vDist[s] = 0;             // distancia hasta s es 0
	cola[k++] = s;           // agregar primer termino s a la cola
	for (int i = 0; i < k; i++) {
	// para todos los nodos adyacentes de cola[i]
		for (int j = 0; j < (int)A[cola[i]].size(); j++) {
			// si el vecino no se ha visitado
			if (vDist[A[cola[i]][j]] < 0) {
			// actualizar su distancia
				vDist[A[cola[i]][j]] = vDist[cola[i]] + 1;
				// si encontramos t, devolver resultado
				if (A[cola[i]][j] == t) return vDist[t];
				// agregar a la cola
				cola[k++] = A[cola[i]][j];
			}
		}
	}
	return -1;
}


int main() {
	int c;
	cin >> c;
	bool firstSpace = false;
	while(c > 0) {

		cin >> N; // numero de nodos que habra

		// Limpio la matriz inicial entre casos
		for(int i = 0; i < N; ++i) A[i].clear();
		for(int i = 0; i < N; ++i) {
			int camar, nAdj;
			// leo camarada| num_adyacentes y los pusheo en el vector
			cin >> camar >> nAdj;
			while (nAdj > 0) {
				int adj;
				// leo adyacente
				cin >> adj;
				A[camar].push_back(adj);
				A[adj].push_back(camar);
				--nAdj;
			}
		}

		int c1, c2;
		cin >> c1 >> c2;

		if(firstSpace) cout << endl;
		firstSpace = true;
		int res = BFS(c1,c2) -1;
		// Si no hay un camino posible, los intermediarios son 0
		if(res < 0) res = 0;
		cout << c1 << " " << c2 << " " << res << endl;
		--c;
	}
	return 0;
}