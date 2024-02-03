#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'
#define INF 1e9 + 7


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    string sufix;
    for(auto i : s){
        sufix += i;
        if(i == '.') sufix.clear();
    }
    cout << sufix << endl;
    
    
}