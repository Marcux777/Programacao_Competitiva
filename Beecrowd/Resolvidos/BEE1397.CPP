#include <iostream>
using namespace std;
int main(){
	int n;
	int a, b, c1, c2;
	cin >> n;
	while(n!=0){
		c1 = 0, c2 = 0;
		for(int i = 0;i < n; i++){
			cin >> a >> b;
			if(a > b){
				c1++;
			} else if (b > a){
				c2++;
			}
		}
		cout << c1 << " " << c2 << endl;
		cin >> n;
	}
}
