#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    char O;
    double M[12][12];
    float soma;
    cin >> O;
    cout << setprecision(1) << fixed;
    soma = 0;
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            cin >> M[i][j];
        }
    }
    for(int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++){
            if(i+j>=12 && j < i){
                soma += M[i][j];
            }
        }
    }
    if(O == 'S'){
        cout << soma << endl;
    } else if (O == 'M'){
        cout << soma/33.0 << endl;
    }
}