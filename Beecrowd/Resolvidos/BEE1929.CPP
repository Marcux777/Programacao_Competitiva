#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if(a > abs(b-c) && a < b+c){
		cout << "S" << endl;
		return 0;
	}else{
		if(b > abs(a-c) && b < a+c){
			cout << "S" << endl;
			return 0;
		}else{
			if(c > abs(a-b) && c < a+b){
				cout << "S" << endl;
				return 0;
			}else{
				if(d > abs(a-b) && d < a+b){
					cout << "S" << endl;
					return 0;
				}else{
					if(d > abs(a-c) && d < a+c){
						cout << "S" << endl;
						return 0;
					}else{
						if(d > abs(b-c) && d < b+c){
							cout << "S" << endl;
							return 0;
						}else{
							cout << "N" << endl;
						}
					}
				}
			}
		}
	}
}
