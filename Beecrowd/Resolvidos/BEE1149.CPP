#include <iostream>
using namespace std;
int main(){
    int a, n, soma = 0;
    cin >> a >> n;
    while (n <= 0){
        cin >> n;
    }
    for(int i = 1; i <= n; i++){
        soma += a;
        a++;
    }
    cout << soma << endl;
}