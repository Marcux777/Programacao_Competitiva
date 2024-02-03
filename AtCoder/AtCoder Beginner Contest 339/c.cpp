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
    int n, menorSaldo = 0, total = 0;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
        total += i;
        menorSaldo = min(menorSaldo, total);
    }
    total = -menorSaldo;
    for(auto i : v){
        total += i;
    }
    cout << total << endl;
}