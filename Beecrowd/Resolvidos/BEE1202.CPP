#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string fila;
        cin >> fila;

        int n = 0;
        for (char c : fila) {
            if (c == '1') {
                n++;
            }
        }

        int fib = 0, a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            fib = (a + b) % 100;
            a = b;
            b = fib;
        }

        int codigo;
        cin >> codigo;

        if (fib % 100 == codigo) {
            cout << fib / 100 << fib / 10 % 10 << fib % 10 << endl;
        } else {
            cout << "0\n";
        }
    }

    return 0;
}
