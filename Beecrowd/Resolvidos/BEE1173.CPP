#include <iostream>
using namespace std;
int main(){
    int n[10],soma;
    cin >> n[0];
    soma = n[0];
    cout << "N[" << 0 << "] = " << soma << endl;
    for (int i = 1; i < 10; i++){
        n[i]= 2 * soma;
        soma = n[i];
        cout << "N[" << i << "] = " << soma << endl;
    }
}