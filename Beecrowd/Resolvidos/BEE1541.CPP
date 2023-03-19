#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int a,b,area,perc,x,n,raiz;
    cin >> a;
    while(a != 0){
        cin >> b >> perc;
        area = a*b;
        x = area*100/perc;
        raiz = sqrt(x);
        cout << raiz << endl;
        cin >> a;
    }
}