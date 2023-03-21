#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    int vetor[5];
    cin >> a >> b >> c;
    vetor[0] = b*2 + c*4;
    vetor[1] = a*2 + c*2;
    vetor[2] = a*4 + b*2;
    if (vetor[0] <= vetor[1] && vetor[0]<=vetor[2]){
        cout << vetor[0] << endl;
    } else if (vetor[1] <= vetor[0] && vetor[1]<=vetor[2]){
        cout << vetor[1] << endl;
    } else{
        cout << vetor[2] << endl;
    }
}