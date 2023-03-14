#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n,x, y;
    float div;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        if (y == 0){
        cout << "divisao impossivel" << endl;
        } else {
            cout << setprecision(1) << fixed;
            cout << x/double(y) << endl;
        }
    }
    return 0;
}