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
void solve()
{
    string s;
    map<char, int> dic;
    cin >> s;
    for (auto i : s)
    {
        if (dic.find(i) != dic.end())
        {
            dic[i]++;
        }
        else
        {
            dic[i] = 1;
        }
    }
    int c = 0;
    if (dic.size() % 2 == 0)
    {
        while (c < dic.size())
        {
            c++;
            int igual = 0;
            for (auto j : dic)
            {
                if (j.second == c)
                {
                    igual++;
                }
            }
            if (igual != 0 && igual != 2)
            {
                cout << "No\n";
                return;
            }
        }
    }else{
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
}
int32_t main()
{
    IOS;
    int tt = 1;
    while (tt--)
        solve();
    return 0;
}