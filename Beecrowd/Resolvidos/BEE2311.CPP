#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main(){
    int n, i = 1;
    float nota[7],dif,menor,maior,notae;
    string nome;
    cin >> n;
    while(i <= n){
        cout << setprecision(2) << fixed;
        maior = -1;
        menor = 10000;
        notae = 0;
        cin >> nome;
        cin >> dif;
        for(int j = 0; j < 7; j++){
            cin >> nota[j];
            notae += nota[j];
            if(nota[j] < menor){
                menor = nota[j];
            }
            if (nota[j] > maior){
                maior = nota[j];
            }
        }
        cout << nome << " " << (notae-maior-menor)*dif << endl;
        i++;
    }
}