#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n, cod, quant;
    float soma = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> cod >> quant;
        if (cod == 1001){
            soma += quant*1.50;
        }
        else {
            if(cod == 1002){
                soma += quant*2.50;
            } 
            else {
                if(cod == 1003){
                    soma += quant*3.50;
                }
                else{
                    if(cod == 1004){
                        soma += quant*4.50;
                    }
                    else{
                        soma += quant*5.50;
                    }
                }
            }
        }
    }
    cout << setprecision(2) << fixed;
    cout << soma << endl;
}