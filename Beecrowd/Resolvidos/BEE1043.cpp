#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    float a,b,c, P, A;
    cin >> a >> b >> c;
    if (b-c < a && a < b+c){
        if (a - c < b && b < a+c){
            if (a - b < c && c < a+b){
                P = a+b+c;
                cout << setprecision(1) << fixed;
                cout << "Perimetro = " << P << endl;
            }
        }
    } else {
        A = (a+b)*c/2;
        cout << setprecision(1) << fixed;
        cout << "Area = " << A << endl;
    }
}