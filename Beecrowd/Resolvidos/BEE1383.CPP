#include <iostream>
#include <string>
using namespace std;
int main(){
    int n, m[10][10];
    string R;
    int soma[9] = {0};
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 9; j++){
            for(int k = 0; k < 9; k++){
                cin >> m[j][k];
            }
        }
        R = "SIM";
        //essa estrutura vai olhar linha e colona do sudoku;
        for(int j = 0; j < 9; j++){
            for(int k = 0; k < 9; k++){
                for(int l = 0; l < 9 && l != k; l++){
                    if(m[j][k] == m[j][l]){
                        R = "NAO";
                    } else {
                        for(int c = 0; c < 9 && c != j; c++){
                            if(m[j][k] == m[c][k]){
                                R = "NAO";
                            }
                        }
                    }
                }
            }
        }
        //essa estrutura vai olhar a matriz 3x3 do sudoku
        for(int k = 0; k < 9; k++){
            for(int j = 0; j < 9; j++){
                if(k/3 == 0){
                    if(j/3 == 0){
                        soma[0] += m[k][j];
                    } else {
                        if(j / 3 == 1){
                            soma[1] += m[k][j];
                        } else {
                            soma[2] += m[k][j];
                        }
                    }
                } else{
                    if(k/3 == 1){
                        if(j/3 == 0){
                        soma[3] += m[k][j];
                    } else {
                        if(j / 3 == 1){
                            soma[4] += m[k][j];
                        } else {
                            soma[5] += m[k][j];
                        }
                    }
                    } else {
                        if(j/3 == 0){
                        soma[6] += m[k][j];
                    } else {
                        if(j / 3 == 1){
                            soma[7] += m[k][j];
                        }
                        else {
                            soma[8] += m[k][j];
                            }
                        }
                    }
                }
            }
        }
        for(int j = 0; j < 9; j++){
            if(soma[j] != 45){
                R = "NAO";
            }
        }
        cout << "Instancia " << i+1 << endl;
        cout << R << "\n"<< endl;
        for(int l = 0; l < 9; l++){
            soma[l] = 0;
        }
    }
}