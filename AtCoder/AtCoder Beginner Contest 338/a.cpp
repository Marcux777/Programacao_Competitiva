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
    int c = 0;
    for(auto i : s) if(isupper(i)) c++;

    if(c == 1 && isupper(s[0])) cout << "Yes\n";
    else cout << "No\n";
    
}