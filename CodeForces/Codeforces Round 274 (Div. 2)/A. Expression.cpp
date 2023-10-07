#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int v[] = {(a+b+c), (a*b*c), (a+b)*c, (b+c)*a, (a*b)+c, (b*c)+a};
    sort(v, v+6);
    cout << v[5] << endl;
}