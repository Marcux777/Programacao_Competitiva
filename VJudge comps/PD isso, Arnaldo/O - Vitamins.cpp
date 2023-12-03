#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define INF 1e10

int N;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    vector<int> valor(N);
    vector<string> vitas(N);
    for (int i = 0; i < N; i++){
        cin >> valor[i] >> vitas[i];
        sort(vitas[i].begin(), vitas[i].end());
    }
    
    


    DP[0][0][0] = 0;
}