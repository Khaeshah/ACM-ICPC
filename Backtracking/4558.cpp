// The first vertex is the one with the largest y value. If two vertices have the same y value, the one with
// the smaller x value is the first.

// Vertices are given in clockwise order around the polygon.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second

typedef int T;       // tipo de coordenada
typedef pair<int,int> P;

// calcular el producto vectorial entre (p,q) y (p,r)
T xp(P p, P q, P r) {
  return (q.X-p.X)*(r.Y-p.Y) - (r.X-p.X)*(q.Y-p.Y);
}

// calcular el cuadrado de la longitud de (p,q)
T sd(P p, P q) {
  return (q.X-p.X)*(q.X-p.X) + (q.Y-p.Y)*(q.Y-p.Y);
}


struct Punto {
  P p, q;
  Punto(P &a, P &b) : p(a), q(b) {}
  bool operator <(const Punto &pt) const {
    T res = xp(q, p, pt.p);
    return res > 0 || (res == 0 && sd(p, q) > sd(pt.p, pt.q));
  }
};

vector<P> convexhull(vector<P> & v) {
	sort(v.begin(), v.end());
	vector<Punto> u;
	for(unsigned int i = 1; i < v.size(); ++i) {
		u.push_back(Punto(v[i],v[0]));
	}
	sort(u.begin(),u.end());

	vector<P> l;
	l.push_back(v[0]);
	l.push_back(u[0].p);
	for(unsigned int i = 1; i < u.size(); ++i) {
		P p = l.back();
		l.pop_back();
		T o = xp(l.back(), p, u[i].p);
		if(o == 0) l.push_back(u[i].p);
		else if (o > 0) {
			l.push_back(p);
			l.push_back(u[i].p);
		}
		else {
			while(o <= 0 && 1 < l.size()) {
				p = l.back();
				l.pop_back();
				o = xp(l.back(), p, u[i].p);
			}
			l.push_back(p);
			l.push_back(u[i].p);
		}
	}
	return l;
}

int main() {
	int p;
	int caso = 1;
	cin >> p;
	while(p--) {
		vector<P> v;
		int set, N;
		cin >> set >> N;
		while(N--) {
			int x,y;
			cin >> x >> y;
			v.push_back(make_pair(x,y));
		}
		vector<P> res;
		res = convexhull(v);
		cout << "Caso " << caso << " " << res.size() << endl;
		for(unsigned int i = 0; i < res.size(); ++i) {
			cout << res[i].first << " " << res[i].second << endl;
		}
		++caso;
	}
}