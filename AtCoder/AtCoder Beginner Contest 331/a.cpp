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
    int M,D, y, m, d;
    cin >> M >> D;
    cin >> y >> m >> d;

    if(d<D){ d++;}
    if(d == D && m < M) {m++; d = 1;}
    if(d == D && m == M) { y++, d = 1; m = 1;}
    cout << y << " " << m <<" " << d << endl;
}