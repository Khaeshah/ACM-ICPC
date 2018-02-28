#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <string>
#include <iterator>
using namespace std;

int main() {
	int t;
	cin >> t;

	int i = 0;
	// t es el numero de casos
	while(i < t) {
		int n;
		// n es la cantidad de robots que leere
		cin >> n;
		vector<string> v;
		while(n > 0) {
			string s;
			cin >> s;
			v.push_back(s);
			--n;
		}
		int d;
		// d es el numero de lineas de robots que leere
		cin >> d;
		set<string> setNames;

		// Para evitar leer una linea vacia
		cin.ignore();
		while(d > 0) {
			// Spliteo el input en un vector de strings ya que de lo contrario da problemas al leer
			string s;
			getline(cin,s);
			stringstream ss(s);
			istream_iterator<string> begin(ss);
			istream_iterator<string> end;
			vector<string> vStrings(begin,end);
			for(string t2 : vStrings) setNames.insert(t2);
			--d;		
		}
		// Output
		cout << "Test set " << i+1 << ":" << endl;
		for(int j = 0; j < v.size(); ++j) {
			cout << v[j] << " is ";
			if(setNames.count(v[j]) >= 1) cout << "present" << endl;
			else cout << "absent" << endl;
		}
		cout << endl;
		++i;
	}
}

/* Version anterior
int main() {
	int t;
	cin >> t;

	int i = 0;
	while(i < t) {
		int n;
		cin >> n;
		map<string,bool> mapa;
		while(n > 0) {
			string s;
			cin >> s;
			mapa.insert(pair<string,bool>(s, false));
			--n;
		}
		int d;
		cin >> d;
		while(d > 0) {
			string s;
			while(cin >> s and s != "\n") {
				cout << "Ha entrado " << s << endl;
				map<string,bool>::iterator it = mapa.find(s);
				if(it != mapa.end()) it->second = true;
			}
			--d;
		}
		++i;
		cout << "Test set " << i << ":" << endl;
		for(map<string,bool>::iterator it = mapa.begin(); it != mapa.end(); ++it) {
			cout << it->first << " is ";
			if(it->second) cout << "present" << endl;
			else cout << "absent" << endl;
		}
	}
}*/