#include <iostream>
using namespace std;

int main() {
	int n, x, y;
	cin >> n;
	while (n > 0) {
		cin >> x >> y;
		if(x < y) cout << "NO BRAINS" << endl;
		else cout << "MMM BRAINS" << endl; 
		--n;
	}
}