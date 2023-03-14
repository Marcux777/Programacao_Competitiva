#include <iostream>

using namespace std;

int main(){
    int a,b,c, ref = 0, total = 0;
    cin >> a >> b >> c;
    while(a >= c){
        ref = a/c;
        total += ref;
        a = ref + a%c;
    }
    b = b+a;
    while(b >= c){
        ref = b/c;
        total += ref;
        b = ref + b%c;
    }
    cout << total << endl;
}