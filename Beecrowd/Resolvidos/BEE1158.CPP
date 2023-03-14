#include <iostream>
using namespace std;
int main(){
    int n, x,y, soma;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        if (x%2 == 1){
            soma = 0;
            for(int j = 1; j <= y; j++){
                soma += x;
                x+=2;
            }
        } 
        else {
            x++;
            soma = 0;
            for(int j = 1; j<=y; j++){
                soma += x;
                x+=2;
            }
        }
        
        cout << soma << endl;
    }
}