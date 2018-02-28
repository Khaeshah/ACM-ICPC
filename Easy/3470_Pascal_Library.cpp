#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, d, a;
	while(cin >> n >> d and n != 0 and n != 0) {
		vector<int> alumni(n);

		// Input
		for(int i = 0; i < d; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> a;
				alumni[j] += a;
			}
		}

		// Output
		bool allDinners = false;
		for(int i = 0; i < alumni.size(); ++i) {
			if(alumni[i] == d) allDinners = true;
		}

		if(allDinners) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}