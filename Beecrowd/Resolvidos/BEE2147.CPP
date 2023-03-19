#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        double tam = s.size();
        cout << fixed << setprecision(2);
        cout << tam/100.00 << endl;
    }
}