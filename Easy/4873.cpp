#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	int p;
	cin >> p;

	while(p > 0) {
		int n;
		string s;
		cin >> n;
		cin >> s;
		map<string,int> mapa;

		for(int i = 0; i < 38; ++i) {
			string aux = "";
			aux += s[i];
			aux += s[i+1];
			aux += s[i+2];
			++mapa[aux];
		}
		cout << n << " " << mapa["TTT"] << " " << mapa["TTH"] << " " << mapa["THT"] << " " << mapa["THH"] << " " << mapa["HTT"] << " " << mapa["HTH"] << " " << mapa["HHT"] << " " << mapa["HHH"] << endl;
		--p;
	}	
}

/* 
Solucion alternativa mas ineficiente

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int p;
	cin >> p;

	// Para cada dataset
	for(int i = 0; i < p; ++i) {
		int n;
		string s;
		size_t pos = 0;
		cin >> n;
		cin >> s;

		vector< vector<int> > appear(p, vector<int> (8));
		//string current;
		// Recorro el string en busca de los patrones
		//for(int j = 0; j < 38; ++j) {	
		while((pos = s.find("TTT",pos)) != std::string::npos) {
			++appear[n-1][0];
			++pos;
		}
		pos = 0;
		while((pos = s.find("TTH",pos)) != std::string::npos) {
			++appear[n-1][1];
			++pos;
		}
		pos = 0;
		while((pos = s.find("THT",pos)) != std::string::npos) {
			++appear[n-1][2];
			++pos;
		}
		pos = 0;
		while((pos = s.find("THH",pos)) != std::string::npos) {
			++appear[n-1][3];
			++pos;
		}
		pos = 0;
		while((pos = s.find("HTT",pos)) != std::string::npos) {
			++appear[n-1][4];
			++pos;
		}
		pos = 0;
		while((pos = s.find("HTH",pos)) != std::string::npos) {
			++appear[n-1][5];
			++pos;
		}
		pos = 0;
		while((pos = s.find("HHT",pos)) != std::string::npos) {
			++appear[n-1][6];
			++pos;
		}
		pos = 0;
		while((pos = s.find("HHH",pos)) != std::string::npos) {
			++appear[n-1][7];
			++pos;
		}
		cout << n << " " << appear[i][0] << " " << appear[i][1] << " " << appear[i][2] << " " << appear[i][3] << " " << appear[i][4] << " " << appear[i][5] << " " << appear[i][6] << " " << appear[i][7] << endl;
	}
}
*/