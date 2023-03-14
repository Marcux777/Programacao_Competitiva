#include <iostream>

using namespace std;

int main(){
    int a, b, c, maior,menor,meio;
    cin >> a >> b >> c;
    if (a > b && a > c){
        maior = a;
        if (b > c){
            meio = b;
            menor = c;
            cout << menor << "\n" << meio << "\n" << maior << endl;
        } else{
            meio = c;
            menor = b;
            cout << menor << "\n" << meio << "\n" << maior << endl;
        }
    }
    if (b >a && b > c){
        maior = b;
        if (a > c){
            meio = a;
            menor = c;
            cout << menor << "\n" << meio << "\n" << maior << endl;
        }
        else {
            meio = c;
            menor = a;
            cout << menor << "\n" << meio << "\n" << maior << endl;
        }
    }
    if (c > a && c > b){
        maior = c;
        if (a > b){
            meio = a;
            menor = b;
            cout << menor << "\n" << meio << "\n" << maior << endl;
        } else {
            meio = b;
            menor = a;
            cout << menor << "\n" << meio << "\n" << maior << endl;
        }
    }
    cout << "\n" << a << "\n" << b << "\n" << c << endl;
}