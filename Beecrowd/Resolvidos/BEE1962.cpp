#include <iostream>
using namespace std;
int main(){
    int n, ano;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ano;
        if(2014 - ano < 0){
            cout << -1*(2014 - ano) << " A.C." << endl;
        } else {
            cout << 2015-ano << " D.C." << endl;
        }
    }
}