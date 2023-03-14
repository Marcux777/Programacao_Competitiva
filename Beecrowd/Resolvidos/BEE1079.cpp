#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n;
    float nota1,nota2,nota3,media;
    cin >> n;
    cout << setprecision(1) << fixed;
    for (int i = 0; i < n; i++){
        cin >> nota1 >> nota2 >> nota3;
        media = (nota1*2 + nota2*3 + nota3*5)/(2+3+5);
        cout << media << endl;
    }
}