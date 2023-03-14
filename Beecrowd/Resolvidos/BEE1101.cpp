#include <iostream>
using namespace std;
int main(){
    int m,n,aux,soma;
    cin >> m >> n;//m é o maior e n o menor
    while (m > 0 && n > 0){
        soma = 0;
        if (m<n){
            aux = m;
            m = n;
            n = aux;
        }
        for (int i = n; i <= m; i++){
            cout << i << " ";
            soma += i;

        }
        cout << "Sum=" << soma << endl;
        cin >> m >> n;
    }
    return 0;
}