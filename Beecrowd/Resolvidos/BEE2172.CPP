#include <iostream>
using namespace std;
int main(){
    long long int x, exp;
    cin >> x >> exp;
    while(x != 0 && exp != 0){
        cout << x*exp << endl;
        cin >> x >> exp;
    }
}