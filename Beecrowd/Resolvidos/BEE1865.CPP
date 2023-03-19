#include <iostream>
#include <string>
using namespace std;
int main(){
    int c,n;
    string nome;
    cin >> c;
    for(int i = 0; i < c; i++){
        cin >> nome >> n;
        if (nome == "Thor"){
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }
}