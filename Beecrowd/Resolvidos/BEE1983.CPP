#include <iostream>

using namespace std;

int main(){
    float maiornota, nota;
    int matricula,n,escolhido;
    cin >> n;
    maiornota = -1;
    for(int i = 0; i < n; i++){
        cin >> matricula >> nota;
        if (nota > maiornota){
            maiornota = nota;
            escolhido = matricula;
        }
    }
    if (maiornota < 8.0){
        cout << "Minimum note not reached" << endl;
    } else {
        cout  << escolhido << endl;
    }
}