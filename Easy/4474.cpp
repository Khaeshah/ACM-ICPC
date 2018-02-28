#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string s;
	while(cin >> s and s != "*") {
		int total;
		total = 0;
		vector<pair<int, bool> > dist(s.size());
		
		// Input de distancias del vector
		for(unsigned int i = 0; i < s.size(); ++i) {
			bool assigned = false;
			int valor = abs('a' - s.at(i));
			// Si esta mas cerca por arriba
			if(valor > 13) {
				valor = 26-valor;
				assigned = true;
			}
			dist[i].first = valor;
			if(!assigned) dist[i].second = false;
			else dist[i].second = true;
		}

		int ultimoCambio = 0;
		for(unsigned int i = 0; i < dist.size()-1; ++i) {
			//Si entro en un cambio
			if(dist[i].second != dist[i+1].second) {
				int maxIntern = 0;
				bool noStop = dist[i].second;
				// Obtengo el valor maximo de la subseccion
				for(int j = i; j >= 0 and dist[j].second == noStop; --j) {
					if(dist[j].first > maxIntern) {
						maxIntern = dist[j].first;
					}
				}
				total += maxIntern;
				ultimoCambio = i+1;
			}
		}

		int temp = 0;
		// Trato el ultimo caso:
		for(int j = dist.size()-1;j >= ultimoCambio; --j) {
			if(dist[j].first > temp) {
				temp = dist[j].first;
			}
					
		}
		total += temp;
		cout << total << endl;
	}
}