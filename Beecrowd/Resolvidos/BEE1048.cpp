#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    float sal, percsal;
    int perc;
    cin >> sal;
    if (sal == 400.00){
        percsal = sal*15/100;
        perc = 15;
    } else {
        if (sal >= 400.01 && sal <= 800.00){
            percsal = sal*12/100;
            perc = 12;
        } else {
            if (sal >= 800.01 && sal <= 1200.00){
            percsal = sal*10/100;
            perc = 10;
        } else {
            if (sal >= 1200.01 && sal <= 2000.00){
            percsal = sal*7/100;
            perc = 7;
        } else {
            if (sal > 2000.00){
            percsal = sal*4/100;
            perc = 4;
        }
        }
        }
        }
    }
    cout << setprecision(2) << fixed;
    cout << "Novo salario: " << sal+percsal << endl; 
    cout << "Reajuste ganho: " << percsal << endl;
    cout << "Em percentual: " << perc << " %" << endl;
}