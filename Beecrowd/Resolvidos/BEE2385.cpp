#include <iostream>
using namespace std;
int main(){
    int n, P, Q, R, S, X, Y, i, j;
    long long int C = 0;
    cin >> n;
    cin >> P >> Q >> R >> S >> X >> Y;
    cin >> i >> j;
    for(int l = 1; l <= n; l++){
        C += ((P*i + Q*l)%X)*((R*l + S*j)%Y);
    
    }
    cout << C << endl;
}