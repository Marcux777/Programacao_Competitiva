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
#define dbg(...) cerr << "(" << __VA_ARGS__ << "):", dbg_out(__VA_ARGS__), cerr << endl

vector<int> G[26];
int vis[26], onStack[26];
stack<int> st;
vector<int> order;

bool dfs(int v) {
    vis[v] = 1;
    onStack[v] = 1;
    for(int u : G[v]) {
        if(!vis[u] && dfs(u)) return true;
        else if(onStack[u]) return true;
    }
    st.push(v);
    onStack[v] = 0;
    return false;
}

signed main() {
    IOS;

    vector<string> words;
    set<int> add;
    string s;
    while(cin >> s && s != "#") {
        words.push_back(s);
    }

    for(int i = 0; i < words.size() - 1; i++) {
        for(int j = 0; j < min(words[i].size(), words[i + 1].size()); j++) {
            if(words[i][j] != words[i + 1][j]) {
                add.insert(words[i][j] - 'A');
                add.insert(words[i + 1][j] - 'A');
                G[words[i][j] - 'A'].push_back(words[i + 1][j] - 'A');
                break;
            }
        }
    }

    memset(vis, 0, sizeof(vis));
    memset(onStack, 0, sizeof(onStack));

    for(int i = 0; i < 26; i++) {
        if(!vis[i] && dfs(i)) {
            cout << "Impossible\n";
            return 0;
        }
    }

    while(!st.empty()) {
        cout << char('A' + st.top());
        st.pop();
    }
    cout << "\n";

    return 0;
}
