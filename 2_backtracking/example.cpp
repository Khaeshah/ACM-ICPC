#include <iostream>
#include <string>
using namespace std;

// guardo en word lo que ya he hecho
int n;
string word;
string con, voc;

// k = profundidad donde estoy
void recGen(int k) {
	// caso base
	if(k == (2*n)) cout << word << endl;
	else {
		// cuando k es par itero en consonantes, impar en vocales
		string letters = con;
		if(k % 2) letters = voc;
		// quan k es par, itero sobre consonantes
		for(int i = 0; i < n; ++i) {
			// pongo en mi vector de word la consonante en posicion i
			// y llamo a la funcion recursiva, comprobando que no este puesta antes
			word[k] = letters[i];

			bool found = false;
			for(int j = 0; j < k; ++j) {
				// |= es el or entre valor actual de found y letters
				found |= word[j] == letters[i];
			}
			// llamo a la funcion recursiva si no esta la letra
			if(!found) recGen(k+1);
		}
	}
}
int main() {
	cin >> n >> con >> voc;
	word = string(2*n, 'a');
	recGen(0);
}