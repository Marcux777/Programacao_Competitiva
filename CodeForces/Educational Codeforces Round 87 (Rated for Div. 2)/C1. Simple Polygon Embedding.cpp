#include <bits/stdc++.h>

using namespace std;

#define PI acos(-1.0)

int main(){
	cout << fixed << setprecision(9);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if (!(n & 1)) {
              cout << 1.0/tan(PI/(2.0*n)) << endl;
        } else {
            cout << cos(PI/(4.0*n))/sin(PI/(2.0*n)) << endl;
        }
	}
	
}