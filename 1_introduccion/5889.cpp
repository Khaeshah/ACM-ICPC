#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();
	vector<int> points(n);
	
	for(int i = 0; i < n; ++i) {
		string s;
		getline(cin,s);
		// Tratar los puntos y luego sacar output, no hace falta guardar
		for(unsigned int j = 0; j < s.size(); ++j) {
			if(s[j] == 'g' or s[j] == 'G') ++points[i];
			else if(s[j] == 'b' or s[j] == 'B') --points[i];
		}
		cout << s << " is ";
		if(points[i] > 0) cout << "GOOD" << endl;
		else if(points[i] == 0) cout << "NEUTRAL" << endl;
		else cout << "A BADDY" << endl; 
	}
}