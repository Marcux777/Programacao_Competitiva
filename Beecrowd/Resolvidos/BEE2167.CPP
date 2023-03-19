#include <iostream>
using namespace std;
int falha(long long int *x, int y){
    for(int i = 1; i < y; i++){
        if(x[i] < x[i-1]){
            return i+1;
            break;
        } else if (i == y-1){
            return 0;
        }
    }
}
int main(){
    int n;
    long long v[10000];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << falha(v, n) << endl;
}