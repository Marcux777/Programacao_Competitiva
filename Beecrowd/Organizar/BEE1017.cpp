#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int a,b;
    float l,dist;
    cin >> a;
    cin >> b;
    dist = a*b;
    l = dist/12;
    cout << setprecision(3) << fixed;
    cout << l << endl;
}