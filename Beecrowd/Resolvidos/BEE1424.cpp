#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    while(cin >> n >> q){
        vector<int> v(n);
        unordered_map<int, vector<int>>mp;
        for(auto i = 0; i < n; i++){
            cin >> v[i];
            mp[v[i]].push_back(i);
        }
        while(q--){
            int x, y;
            cin >> x >> y;
            x--;
            if(mp.count(y) && mp[y].size() > x)
                cout << mp[y][x]+1 << endl;
            else cout << 0 << endl;
        }
    }
}