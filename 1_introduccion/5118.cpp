#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int q;
	cin >> q;
	cin.ignore();
	vector<string> rules(q);
	for(int i = 0; i < q; ++i) {
		string s;
		getline(cin,s);
		rules[i] = s;
	}
	int r;
	cin >> r;
	while(r > 0) {
		int number;
		cin >> number;
		cout << "Rule " << number << ": ";
		if(number-1 >= 0 and number-1 < q) cout << rules[number-1] << endl;
		else cout << "No such rule" << endl;
		--r;
	}
}