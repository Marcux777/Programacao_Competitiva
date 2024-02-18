#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, d;
    cin >> a >> b >> d;
    for(int i = a; i <= b; i+=d){
        cout << i << " ";
    }
    cout << endl;
}