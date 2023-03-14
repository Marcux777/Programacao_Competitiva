#include <iostream>
#include <string>
using namespace std;
int main(){
    string cpf;
    int c[14];
    int b1, b2;
    
    while(cin >> cpf){
        for(int i = 0; cpf[i]; i++){
            if((int)cpf[i] == 45 || (int)cpf[i] == 46){
                continue;
            }
            c[i] = (int)cpf[i] - 48;
        }
        b1 = 0;
        b2 = 0;
        b1 = c[0]*1 + c[1]*2 + c[2]*3 + c[4]*4 + c[5]*5 + c[6]*6 + c[8]*7 + c[9]*8 + c[10]*9;
        b2 = c[0]*9 + c[1]*8 + c[2]*7 + c[4]*6 + c[5]*5 + c[6]*4 + c[8]*3 + c[9]*2 + c[10]*1;
        b1 = (b1%11)%10;
        b2 = (b2%11)%10;
        if(b1 == c[12] && b2 == c[13]){
            cout << "CPF valido" << endl;
        } else {
            cout << "CPF invalido" << endl;
        }
    }
}