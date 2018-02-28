#include <iostream>
using namespace std;

int main() {
	int days;
	while(cin >> days and days != 0) {
		int cobro = 1;
		int total = 0;
		int dia = 1;
		int dias = days;
		bool finished = false;
		
		while (dias > 0) {
			if(dia == 0) {
				++cobro;
				dia = cobro;
			}
			total += cobro;
			dias--;
			dia--;
		}
		cout << days << " " << total << endl;
		total = 0;
	}
}