#include <bits/stdc++.h>

using namespace std;

#define int long int

signed main(){
    int n; cin >> n;
    vector<int>v(n);
    map<int, int>mp;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(mp.find(v[i]) == mp.end())
            mp[v[i]] = 1;
        else mp[v[i]]++;
    }
    int maiorRep = 0;
    for(auto i : mp){
        if(i.second > maiorRep){
            maiorRep = i.second;
        }
    }
    int ans = 0;
    for(auto i : mp)
        if(i.second == maiorRep)
            ans++;
    
    cout << ans << endl;
    
}