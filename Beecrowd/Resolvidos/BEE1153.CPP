#include <iostream>
using namespace std;
int fat(int x){
    if(x == 0){
        return 1;
    }
    return fat(x-1)*x;
}
int main(){
    int n;
    cin >> n;
    cout << fat(n) << endl;
}