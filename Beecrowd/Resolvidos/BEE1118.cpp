#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	float P1,P2,media;
	int n;
	cin >> P1;
    cout << setprecision(2) << fixed;
	while (P1 > 10 || P1 < 0){
		cout << "nota invalida" << endl;
		cin >> P1;
	}
	cin >> P2;
	while (P2 > 10 || P2 < 0){
		cout << "nota invalida" << endl;
		cin >> P2;
	}
	media = (P1 + P2)/2;
	cout << "media = " << media << endl;
	cout << "novo calculo (1-sim 2-nao)" << endl;
	cin >> n;
	while (n < 0 || n > 2){
	    cout << "novo calculo (1-sim 2-nao)" << endl;
	    cin >> n;
	}
	while (n == 1){
	    cin >> P1;
	    while (P1 > 10 || P1 < 0){
		    cout << "nota invalida" << endl;
		    cin >> P1;
	    }
	        cin >> P2;
	    while (P2 > 10 || P2 < 0){
		    cout << "nota invalida" << endl;
		    cin >> P2;
		}
		media = (P1+P2)/2;
		cout << "media = " << media << endl;
		cout << "novo calculo (1-sim 2-nao)" << endl;
		cin >> n;
		while (n < 0 || n > 2){
	        cout << "novo calculo (1-sim 2-nao)" << endl;
	        cin >> n;
	    }
	} if (n == 2){
	    return 0;
	}
}