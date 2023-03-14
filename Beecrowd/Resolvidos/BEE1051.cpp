#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    float renda,imposto1,imposto2,impostof,imposto3,imposto4;
    cin >> renda;
    cout << setprecision(2) << fixed;
    if (renda < 2000.00){
        cout << "Isento" << endl;
    } if (renda > 2000.00 && renda <= 3000.00){
        imposto1 = renda-2000.00;
        impostof = imposto1*8/100;
        cout << "R$ " << impostof << endl;
    } if (renda > 3000.00 && renda <= 4500.00){
        imposto1 = renda-2000.00;
        imposto2 = imposto1 - 1000.00;
        impostof = (1000*8/100)+(imposto2*18/100);

        cout << "R$ " << impostof << endl;
    } if (renda > 4500.00){
        imposto1 = renda - 4500.00;
        impostof = (1000*8/100)+(1500*18/100)+(imposto1*28/100);
        cout << "R$ " << impostof << endl;
    }
}