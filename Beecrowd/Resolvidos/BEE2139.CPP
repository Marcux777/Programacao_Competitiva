#include <iostream>
using namespace std;
int main(){
    int mes,dia,dias[13] = {0,31,29,31,30,31,30,31,31,30,31,30,25};
    int soma = 0;
    while(cin >> mes){
        cin >> dia;
        soma = 0;
        if(mes >= 2){
            for(int i = 1; i <= mes; i++){
                soma += dias[i-1];
            }
        soma += dia;
        } else {
            soma = dia;
        }
        if (soma == 360){
            cout << "E natal!" << endl;
        } else if (soma == 360-1){
            cout << "E vespera de natal!" << endl;
        } else if (soma < 360){
            cout << "Faltam " << 360-soma << " dias para o natal!" << endl;
        } else {
            cout << "Ja passou!" << endl;
        }
    }
}