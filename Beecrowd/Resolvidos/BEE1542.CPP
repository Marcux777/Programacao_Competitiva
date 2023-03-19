#include <iostream>
#include <math.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double q, d, p, R;
    
    while(cin >> q && q){
		cin >> d >> p;
		R = (q*d/(p-q))*p;
		R = floor(R);
		if(R == 1){
			cout << R << " pagina" << endl;
		}else{
			cout << R << " paginas" << endl;
		}
	}
}
