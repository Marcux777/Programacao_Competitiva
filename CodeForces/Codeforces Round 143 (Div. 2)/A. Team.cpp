#include <iostream>

using namespace std;

int main(){
    int t, certeza = 0;
    cin >> t;
    while(t--){
        int cont = 0;
        for(int i = 0; i < 3; i++){
            int a;
            cin >> a;
            if(a){
                cont++;
            }
        }
        if(cont >= 2){
            certeza++;
        }
    }
    cout << certeza << endl;
}