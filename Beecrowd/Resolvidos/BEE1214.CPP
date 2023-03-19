#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int nota[1000];
    int c, n;
    double soma, media, cont;
    cout << setprecision(3) << fixed;
    cin >> c;
    for(int i =0; i < c; i++){
        cin >> n;
        soma = 0, media = 0, cont = 0;
        for(int j = 0; j < n; j++){
            cin >> nota[j];
            soma += nota[j];
        }
        media = (double)soma/n;
        for(int j = 0; j < n; j++){
            if(nota[j] > media){
                cont++;
            }
        }
        cout << 100.000*cont/n << "%" << endl;
    }
}