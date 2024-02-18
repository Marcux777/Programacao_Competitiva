#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    string s;
    for(int i = 0; i < n; i++){
        s += '1';
        s += '0';
    }
    s+='1';
    cout << s << endl;
}