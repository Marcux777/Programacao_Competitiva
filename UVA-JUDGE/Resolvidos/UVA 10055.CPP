#include <iostream>

using namespace std;

int main(){
    long long int a,b;
    //freopen("saida.txt", "w", stdout);
    while(cin >> a >> b){
        cout << abs(b-a) << endl;
    }
}