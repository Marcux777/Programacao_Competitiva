#include <iostream>
using namespace std;
int main()
{
    long long int a, b, soma = 0;
    cin >> a >> b;
    soma = (a + b) * ((b - a) + 1) / 2;
    cout << soma << endl;
}