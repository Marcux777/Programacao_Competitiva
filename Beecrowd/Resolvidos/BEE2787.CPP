#include <iostream>
using namespace std;
int main(){
    int l,c,cor; //linha e coluna
    cin >> l;
    cin >> c;
    if (l%2==0){
        if (c%2==0){
            cor = 1; // 1 = branca
        } else{
            cor = 0; // 0 = preta
        }
    } else {
        if(c%2!=0){
            cor = 1; // cor branca
        } else {
            cor = 0; // cor preta
        }
    }
    cout << cor << endl;
    return 0;
}