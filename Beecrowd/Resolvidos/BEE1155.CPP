#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    float soma=0;
    for (int i = 1; i <= 100; i++){
        soma += 1/float(i);
    }
    cout << setprecision(2) << fixed;
    cout << soma << endl;
}