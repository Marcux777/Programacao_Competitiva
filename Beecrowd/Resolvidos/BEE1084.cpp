#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define inf LLONG_MAX
#define Ninf LLONG_MIN
#define mod 1000000007

int n, d;
string s;
vector<int> dp;

int f(int id, int quant){
    if(id == n) return 0;
    if(quant == 0) return 0;
    if(dp[id] != -1) return dp[id];

    

    return dp[id] = a;

}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    while(cin >> n >> d && n && d){
        cin >> s;
        reverse(s.begin(), s.end());
        dp = vector<int> (n+1, -1);
        cout << f(0, d) << endl;
    }
    
}