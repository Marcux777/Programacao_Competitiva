#include <iostream>
using namespace std;
int main(){
    int n;
    int vetor[46];
    cin >> n;
    vetor[0] = 0;
    vetor[1] = 1;
    cout << vetor[0] << " " << vetor[1] << " ";
    for (int i = 2; i < n; i++){
        vetor[i] = vetor[i-1] + vetor[i-2];
        if (i == n-1){
            cout << vetor[i];
        } else {
            cout << vetor[i] << " ";
        }
    }
    cout << "\n";
}