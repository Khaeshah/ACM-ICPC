#include <iostream>
using namespace std;

int main() {
	int n, caseNumber;
	cin >> n;
	caseNumber = 1;
	while(n > 0) {
		int c, total, it;
		cin >> c;
		it = c;
		total = 0;
		while(it > 0) {
			for(int i = 0; i < it; ++i) {
				total += i+1;
			}
			--it;
		}
		cout << caseNumber << ": " << c << " " << total << endl;
		--n;
		++caseNumber;
	}
}