#include <bits/stdc++.h>

using namespace std;

#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)
#define pb push_back
#define all(v) v.begin(), v.end()
#define f first
#define s second
#define Unique(v) \
    sort(all(v)); \
    v.erase(unique(all(v)), v.end());
#define sz(v) ((int)v.size())
#define sor(x) sort(all(x))
#define ft front()
#define bk back()
#define endl "\n"
#define rep(i, a, b) for (int i = a; i < (b); ++i)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<pii> vii;
typedef vector<piii> viii;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int mod = 1e9 + 7;
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << _VA_ARGS_ << "):", dbg_out(_VA_ARGS_), cerr << endl

/*
E. Secret Box
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Ntarsis has a box B
 with side lengths x
, y
, and z
. It lies in the 3D coordinate plane, extending from (0,0,0)
 to (x,y,z)
.

Ntarsis has a secret box S
. He wants to choose its dimensions such that all side lengths are positive integers, and the volume of S
 is k
. He can place S
 somewhere within B
 such that:

S
 is parallel to all axes.
every corner of S
 lies on an integer coordinate.
S
 is magical, so when placed at an integer location inside B
, it will not fall to the ground.

Among all possible ways to choose the dimensions of S
, determine the maximum number of distinct locations he can choose to place his secret box S
 inside B
. Ntarsis does not rotate S
 once its side lengths are selected.

Input
The first line consists of an integer t
, the number of test cases (1≤t≤2000
). The description of the test cases follows.

The first and only line of each test case contains four integers x,y,z
 and k
 (1≤x,y,z≤2000
, 1≤k≤x⋅y⋅z
).

It is guaranteed the sum of all x
, sum of all y
, and sum of all z
 do not exceed 2000
 over all test cases.

Note that k
 may not fit in a standard 32-bit integer data type.

Output
For each test case, output the answer as an integer on a new line. If there is no way to select the dimensions of S
 so it fits in B
, output 0
.
*/

vi f(int n) {
    vi factors;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i * i != n) {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}

void solve()
{
    int x, y, z, k;
    cin >> x >> y >> z >> k;

    int m = 0;

    vi factors = f(k);
    sort(factors.begin(), factors.end());

    for (int i = 0; i < factors.size(); ++i) {
        int j = i, l = factors.size() - 1;
        while (j <= l) {
            if (factors[i] * factors[j] * factors[l] == k) {
                vi dims = {factors[i], factors[j], factors[l]};
                sor(dims);
                do {
                    int a = dims[0], b = dims[1], c = dims[2];
                    if (a <= x && b <= y && c <= z) {
                        int locations = (x - a + 1) * (y - b + 1) * (z - c + 1);
                        m = max(m, locations);
                    }
                } while (next_permutation(dims.begin(), dims.end()));
                ++j;
                --l;
            } else if (factors[i] * factors[j] * factors[l] < k) {
                ++j;
            } else {
                --l;
            }
        }
    }

    cout << m << endl;
}

int32_t main()
{
    IOS;
    int tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
