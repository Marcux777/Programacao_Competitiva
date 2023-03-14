#include <iostream>
using namespace std;
int main(){
    int n, x,div;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x;
        div = 0;
        for(int j = 1; j <= x; j++){
            if (x%j == 0){
                div++;
            }
        }
        if (div > 2){
            cout << x << " nao eh primo" << endl;
        } else {
            cout << x << " eh primo" << endl;
        }
    }
}