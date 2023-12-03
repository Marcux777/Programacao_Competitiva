#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define endl '\n'
#define f first
#define s second

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<long long>v(n);
    long long maxi = -1, maxpos = -1;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(maxi < abs(v[i])){
            maxi = abs(v[i]);
            maxpos = i;
        }
    }
    vector<pair<int, int>> ans;
    for(int i=0; i<n; i++){
        if(i == maxpos){
            continue;
        }
        v[i] += v[maxpos];
        ans.push_back({maxpos+1, i+1});
    }
    if(v[0] >= 0){
        for(int i = 1; i < n; i++){
            v[i] += v[i-1];
            ans.push_back({i, i+1});
        }
    }else{
        for(int i = n-2; i >= 0; i--){
            v[i] += v[i+1];
            ans.push_back({i+2, i+1});
        }
    }
    cout << ans.size() << endl;
}