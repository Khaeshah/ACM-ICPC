#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef vector<pair<int,pair<int,int> > > V;
V v;
int N; // numero de nodos 
int mf[2010],ranking[2010];

int set(int n) { // conjunto conexo de n
	if (mf[n] == n) return n;
  	else mf[n] = set(mf[n]); 
  	return mf[n];
}

// coste, <origen, destino>
int kruskal() {
	int a, b, sum = 0;
  	sort(v.begin(), v.end());

  	for (int i = 0; i < N; i++) {
  		mf[i] = i; // inicializar conjuntos conexos
  		ranking[i] = 0;
  	}

  	for (unsigned int i = 0; i < v.size(); i++) {
    	a = set(v[i].second.first);
    	b = set(v[i].second.second);
    	if (a != b) { // si conjuntos son diferentes
    		if(ranking[a] > ranking[b]) mf[b] = a;
    		else {
    			mf[a] = b;
    			ranking[b] += (ranking[a] == ranking[b]);
    		}
      		sum += v[i].first; // agregar coste de arista
    	}
  	}
  	return sum;
}

int main() {
	int c;
	cin >> c;
	bool firstSpace = false;
	while(c > 0) {

		// Borro el vector global
		while (v.size() > 0) {
        	v.erase(v.begin());
        	v.push_back(v.front());
        	v.erase(v.begin());
    	}

		int m, n;
		cin >> m >> n;
		N = m;
		map<string,int> id;
		string c1,c2;
		int cost;
		int nodeID = 0;


		// Para cada link, asigno valores [coste[origen,destino]
		for(int i = 0; i < n; ++i) {
			cin >> c1 >> c2 >> cost;
			v.push_back(make_pair(cost,make_pair(id.count(c1) ? id[c1] : id[c1] = nodeID++,id.count(c2) ? id[c2] : id[c2] = nodeID++)));
		}
		int ans = kruskal();
		if(firstSpace) cout << endl;
		firstSpace = true;

		cout << ans << endl;
		--c;
	}
}