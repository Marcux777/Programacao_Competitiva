#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'
#define INF LLONG_MAX
#define mod 32768

int N;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    vector<int>v(N), V(N);
    for(auto &i : v){ cin >> i;}

    V = v;
    sort(V.begin(), V.end());
    
    vector<int> prefix_sum(N);
    prefix_sum[0] = V[0];
    for(int i = 1; i < N; i++){
        prefix_sum[i] = prefix_sum[i-1] + V[i];
    }
    
    map<int, int>mp;
    for(int i = 0; i < N; i++){
        if(i != N-1 && V[i] != V[i+1]){
            mp[V[i]] = prefix_sum[N-1] - prefix_sum[i];
        }
    }
    for(int i = 0; i < N; i++){
        cout << mp[v[i]] << " ";
    }
    cout << endl;
}