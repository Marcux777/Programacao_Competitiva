#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long soma = 0;
    int c = 0;
    
    while(n >= 2) {
        c++;
        soma += n;
        n /= 2;
    }
    cout << c << endl;
    soma += n;
    
    cout << soma << endl;
    
    return 0;
}
