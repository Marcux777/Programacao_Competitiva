#include <iostream>
using namespace std;
int main(){
    int x;
    cin >> x;
    while (x!=0){
        for(int i = 1; i <= x; i++){
            cout << i;
            if (x != i){
                cout << " ";
            } else {
                cout << endl;
            }
        }
        cin  >> x;
    }
}