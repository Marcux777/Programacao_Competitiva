#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream cin("mowing.in");
    ofstream cout("mowing.out");
    int n; cin >> n;
    vector<pair<char, int>> v(n);
    for(int i = 0; i < n; i++){
        char c;
        int s;
        cin >> c >> s;
        v[i] = {c, s};
    }

    map<pair<int, int>, int> vis;
    int x = 0, y = 0;
    int t = 0;
    int mindiff = INT_MAX;

    map<char, pair<int, int>> dir{
        {'N', {0, 1}},
        {'S', {0, -1}},
        {'E', {1, 0}},
        {'W', {-1, 0}}
    };
    vis[{x, y}] = t;

    for(auto i : v){
        int dx = dir[i.first].first;
        int dy = dir[i.first].second;

        for(int j = 0; j < i.second; j++){
            x += dx;
            y += dy;
            t++;
            if(vis.count({x, y}))
                mindiff = min(mindiff, t - vis[{x, y}]);
            vis[{x, y}] = t;
        }
    }

    if(mindiff == INT_MAX)
        cout << -1 << endl;
    else cout << mindiff << endl;
}