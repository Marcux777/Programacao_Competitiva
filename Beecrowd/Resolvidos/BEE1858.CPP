#include <iostream>
using namespace std;
int main(){
    int n, t[100], menor = 1000, pos, i;
    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> t[i];
        if (t[i] < menor) {
            menor = t[i];
            pos = i;
        }
    }
    cout << pos << endl;
}