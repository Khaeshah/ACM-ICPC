#include <iostream>
#include <map>
using namespace std;

map<string,int> mapa;

void fillMap(string s, int n, int & valor) {
	// Voy asignando un valor para cada letra, ineficiente pero funciona
	if(s.length() == n) {
		mapa[s] = valor;
		++valor;
	}
	else {
		char last;
		if(s.length() == 0) last = 'a';
		else last = s[s.length()-1] +1;
		for(char c = last; c <= 'z'; ++c) {
			fillMap(s+c,n,valor);
		}		
	}
}

int main() {
	string s;
	int valor = 1;
	int i = 0;
	while(i < 6) {
		// Genero valores para cada combinacion
		fillMap("",i+1,valor);
		++i;
	}
	while(cin >> s) {
		cout << mapa[s] << endl;
	}
}