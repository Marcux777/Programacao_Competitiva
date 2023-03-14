#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n, aux, c;
    long int m[150][150];
    cin >> n;
    while(n != 0){
        aux = n;
        c = 1;
        for(int i = 1; i <= n; i++){
          for(int j = 1; j <= n; j++){
                m[i][j] = 1;
            }
        }
        while(aux != 0){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(i > c && j > c && i < aux && j < aux){
                        m[i][j]++;
                    }
                }
            }
            aux--;
            c++;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cout << setw(3) << m[i][j];
                if(j == n){
                    cout << endl;
                } else {
                    cout << " ";
                }
            }
        }
        cout << endl;
        cin >> n;
    }
}