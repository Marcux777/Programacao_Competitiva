#include <iostream>
using namespace std;
int main(){
    int n, M[70][70];
    while(cin >> n){
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n; j++){
                if (j == (n-1)-i){
                    M[i][j] = 2;
                }
                else if (j == i){
                   M[i][j] = 1;
                }
                else {
                    M[i][j] = 3;
                }
                cout << M[i][j];
                if(j == n-1){
                    cout << endl;
                }

            }
        }
    }
}