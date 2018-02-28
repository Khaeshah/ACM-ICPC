#include <iostream>
using namespace std;

int main() {
	int n;
	while(cin >> n and n != 0) {
		int total = 0;
		while(n > 0) {
			total += n*n;
			--n;
		}
		cout << total << endl;
	}
}