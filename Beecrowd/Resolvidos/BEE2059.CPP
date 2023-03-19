#include <iostream>
using namespace std;
int IPR(int a, int b, int c, int d, int e)
{
	if(a == 1){
		if(d == 0){
			if(e == 0){
				if((b+c)%2 == 0){
					return 1;
				} else {
					return 2;
				}
			} else {
				return 1;
			}
		} else {
			if(e == 0){
				return 1;
			} else {
				return 2;
			}
		}
	} else {
		if(d == 0){
			if(e == 0){
				if((b+c)%2 == 1){
					return 1;
				} else {
					return 2;
				}
			} else {
				return 1;
			}
		} else {
			if(e == 0){
				return 1;
			} else {
				return 2;
			}
		}
	}
}

int main()
{
	int p, j1, j2, r, a, v;
	cin >> p >> j1 >> j2 >> r >> a;
	v = IPR(p, j1, j2, r, a);
	cout << "Jogador " << v << " ganha!" << endl;
}
