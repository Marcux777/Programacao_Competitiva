#include <iostream>
using namespace std;
int main(){
    int m[150][150];
    int n, interior;
    while(cin >> n){
        //preenche a matriz com 0
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                m[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                //diagonal principal
                if(i == j){
                    m[i][j] = 2;
                } else{
                    //diagonal secundaria
                    if(i+j == n-1){
                        m[i][j] = 3;
                    }
                }
            }
        }
        interior = n/3; //a parte interior que será preenchida com 1
        for(int i = interior; i < n-interior; i++){
            for(int j = interior; j < n-interior; j++){
                m[i][j] = 1;
            }
        }
        //Parte central da matriz
        m[n/2][n/2] = 4;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << m[i][j];
                if(j == n-1){
                    cout << endl;
                }
            }
        }
        cout << endl;
    }
}