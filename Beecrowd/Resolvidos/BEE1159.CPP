#include <iostream>
using namespace std;
int main(){
    int x, soma;
    cin >> x;
    while(x!=0){
        if (x%2 == 0){
            soma = 0;
            for(int i = 1; i <= 5; i++){
                soma += x;
                x+=2;
            }
        } else {
            x++;
            soma = 0;
            for(int i = 1; i <= 5; i++){
                soma+= x;
                x+=2;
            }
        }
        cout << soma << endl;
        cin >> x;
    }
}