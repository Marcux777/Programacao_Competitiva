#include <iostream>
using namespace std;
int main(){
    float num;
    int n=0;
    for (int i = 0; i < 6; i++){
        cin >> num;
        if (num > 0){
            n++;
        }
    }
    cout << n << " valores positivos" << endl;
}