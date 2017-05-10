#include <iostream>
using namespace std;


// 4 7 10
// 2 6 18
// 0 0 0

int main() {
	int a1, a2, a3;
	while((cin >> a1 >> a2 >> a3) and !(a1 == 0 and a2 == 0 and a3 == 0)) {
		int next;
		if (a1 == 2*a2 - a3) {
			next = a3+(a2-a1);
			cout << "AP " << next << endl;
		}
		else {
			next = a3*(a2/a1);
			cout << "GP " << next << endl;
		}
	}
	return 0;
}