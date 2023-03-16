#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n){
        if(!(n&(n-1))){
            cout << "Alice" << endl;
        }else{
            cout << "Bob" << endl;
        }
        cin >> n;
    }
}