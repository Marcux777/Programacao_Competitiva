#include <iostream>
using namespace std;
int main(){
    int n1,n2;
    cin >> n1 >> n2;
    if(((n1-1)/2) == ((n2-1)/2)){
        cout << "oitavas" << endl;
    } else{
        if(((n1-1)/4) == ((n2-1)/4)){
            cout << "quartas" << endl;
        }else{
            if(((n1-1)/8) == ((n2-1)/8)){
                cout << "semifinal" << endl;
            }else{
                cout << "final" << endl;
            }
        }
    }
}