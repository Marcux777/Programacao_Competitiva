#include <iostream>

using namespace std;

int main(){
    int n, a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        int v, soma = 0;
        for(int j = 0; j < a; j++){
            cin >> v;
            if(j == 0){
                soma += v;
            }else{
                soma += v-1;
            }
        }
        cout << soma << endl;
    }
}