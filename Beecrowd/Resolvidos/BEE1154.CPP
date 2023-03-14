#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int id = 0,i = 0;
    float soma = 0;
    cout << setprecision(2) << fixed;
    cin >> id;
    soma += id;
    while(id > 0) {
        cin >> id;
        if (id > 0){
            soma += id;
        }
        i++;
    }
    cout << soma/i << endl;
}