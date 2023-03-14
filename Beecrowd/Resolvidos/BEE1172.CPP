#include <iostream>
using namespace std;
void vetor_preenchido(int *x){
    for(int i = 0; i < 10; i++){
        if(x[i] < 1){
            x[i] = 1;
        }
        cout << "X[" << i << "] = " << x[i] << endl;
    }
}
int main(){
    int v[10];
    for(int i = 0; i < 10; i++){
        cin >> v[i];
    }
    vetor_preenchido(v);
}