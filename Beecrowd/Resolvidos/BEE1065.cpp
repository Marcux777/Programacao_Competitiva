#include <iostream>
using namespace std;
int main(){
    int num,par = 0;
    for (int i = 0; i < 5; i++){
        cin >> num;
        if (num%2 == 0){
            par++;
        }
    }
    cout << par <<" valores pares" << endl;
}