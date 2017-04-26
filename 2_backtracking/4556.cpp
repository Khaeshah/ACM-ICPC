#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int i = 0;
	while(n > 0) {
		string set, num;
		cin >> set >> num;
		// retorna true si tiene una permutacion mayor
		// si ya es la mayor devuelve falso y los reordena en funcion de la primera permutacion
		if(next_permutation(num.begin(),num.end())) cout << set << " " << num << endl;
		else cout << set << " " << "BIGGEST" << endl;
		--n;
	}
}