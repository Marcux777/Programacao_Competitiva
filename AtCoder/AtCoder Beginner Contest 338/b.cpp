#include <bits/stdc++.h>

using namespace std;

#define int long int
#define endl '\n'
#define INF 1e9 + 7


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    map<char, int> mp;
    for(auto i : s){
        if(!mp[i]){
            mp[i] = 1;
        }else{
            mp[i]++;
        }
    }
    int ans = -1;
    char let;
    for(auto i : mp){
        if(i.second > ans){
            ans = i.second;
            let = i.first;
        }
        else if(i.second == ans){
            let = min(i.first, let);
        }
    }
    cout << let << endl;
}