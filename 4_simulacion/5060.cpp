#include <iostream>
using namespace std;


typedef pair<int,int> luchador;

int exp(int b, int e) {
   if (e == 0) return 1;
   int m = exp(b, e/2);
   if  (e%2 == 0) return m*m;
   else return m*m*b;
}

int main() {
	// 2^n contestants
	// c1 vs c2, c3 vs c4 etc
	// winner c1vc2 vs winner c3vc4
	// cada contestant te P strength
	// the stronger one wins, Pi - Prival
	// es recupera K strength, pero no pot tindre mes de la inicial
	// same contestant = guanya el de menor index
	int T; // testcases
	cin >> T;
	while(T--) {
		int N, K;
		cin >> N >> K;
		int nCases = exp(2,N);
		vector<int> pesos(nCases);
		for(int i = 0; i < nCases; ++i) {
			int peso;
			cin >> peso;
			pesos[i] = peso;
		}


	}
}