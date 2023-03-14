#include <iostream>
using namespace std;
int main(){
    int j,k;
    j = 1;
    k = 60;
    cout << "I=" << j << " J=" << k << endl;
    for (int i = 0; i < 12; i++){
        j = j+3;
        k = k-5;
        cout << "I=" << j << " J=" << k << endl;
    }
}