#include <iostream>
#include <math.h>
using namespace std;
int main(){
    unsigned long long int n, br, al;
    double t;
    cin >> n;
    while(n!=0){
        t = n/90.0;
        br = floor(t*1);
        al = ceil(t*7);
        cout << "Brasil " << br << " x Alemanha " << al << endl;
        cin >> n;
    }
}