#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	int n;
	cin >> n;
	while(n > 0) {
		string s1,s2;
		cin.ignore();
		getline(cin,s1);

		double x1,y1,z1,x2,y2,z2,res,x,y,z;
		x1 = y1 = z1 = x2 = y2 = z2 = res = x = y = z = 0.0;
		cin >> x1 >> y1 >> z1;

		cin.ignore();
		getline(cin,s2);
		
		cin >> x2 >> y2 >> z2;
				
		x = pow(x2-x1,2);
		y = pow(y2-y1,2);
		z = pow(z2-z1,2);

		res = sqrt(x+y+z);

		cout << fixed << setprecision(2);
		cout << s1 << " to " << s2 << ": " << res << endl;
		--n;
	}
}