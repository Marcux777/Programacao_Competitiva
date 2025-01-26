/*
~~ Alguma parte/frase foda de um livro/mangá para dar sorte ~~

Uma vez eu gritei, gradualmente, perdi minha voz.
Uma vez eu chorei, gradualmente, perdi minhas lágrimas.
Uma vez eu sofri, gradualmente, me tornei capaz de suportar tudo.
Uma vez me alegrei, gradualmente, me tornei indiferente ao mundo.
E agora, tudo o que me resta é um rosto sem expressão,
meu olhar é tão firme quanto um monólito,
apenas a perseverança permanece no meu coração.
Este sou eu, um personagem insignificante,
Fang Yuan — A Perseverança.

*/
#if defined(LOCAL) or not defined(LUOGU)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,unroll-loops")
#endif

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
#define Unique(v)                     \
    sort(all(v));                     \
    v.erase(unique(all(v)), v.end()); \
    v.shrink_to_fit()
#define sz(v) ((int)v.size())
#define sor(x) sort(all(x))
#define ft front()
#define bk back()
#define endl "\n"
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
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
typedef tuple<int, int, int> tiii;
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
    int m, n;
    cin >> m >> n;
    
    // mapeamento para atribuir ids únicos a cada cidade
    unordered_map<string, int> id_city;
    int id = 0;
    vector<pair<string, string>> roads(m);
    
    rep(i, 0, m){
        cin >> roads[i].f >> roads[i].s;
        if(id_city.emplace(roads[i].f, id).s) id++;
        if(id_city.emplace(roads[i].s, id).s) id++;
    }
    
    if(id_city.emplace("Rome", id).s) id++;
    
    vvi adj(id, vi());
    for(auto &[a, b] : roads){
        int u = id_city[a];
        int v = id_city[b];
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    int LOG = 20;
    vi depth_arr(id, 0);
    vvi up(id, vi(LOG, -1));
    queue<int> q;
    
    int root = id_city["Rome"];
    q.push(root);
    up[root][0] = -1;
    
    // para computar profundidade e ancestrais para LCA
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto &u : adj[v]){
            if(u != up[v][0]){
                depth_arr[u] = depth_arr[v] + 1;
                up[u][0] = v;
                // Computar ancestrais de 2^k
                rep(k, 1, LOG){
                    if(up[u][k-1] != -1)
                        up[u][k] = up[up[u][k-1]][k-1];
                    else
                        up[u][k] = -1;
                }
                q.push(u);
            }
        }
    }

    // LCA
    auto lca = [&](int u, int v) -> int {
        if(depth_arr[u] < depth_arr[v]) swap(u, v);
        // Nivelar u para a mesma profundidade de v
        for(int k = LOG-1; k >=0; --k){
            if(up[u][k] != -1 && depth_arr[up[u][k]] >= depth_arr[v]){
                u = up[u][k];
            }
        }
        if(u == v) return u;
        // Encontrar o LCA elevando ambos u e v
        for(int k = LOG-1; k >=0; --k){
            if(up[u][k] != -1 && up[u][k] != up[v][k]){
                u = up[u][k];
                v = up[v][k];
            }
        }
        return up[u][0];
    };

    // obter o caminho de um nó até seu ancestral
    auto get_path = [&](int u, int ancestor) -> vi {
        vi path;
        while(u != ancestor){
            path.pb(u);
            u = up[u][0];
        }
        return path;
    };

    while(n--){
        string x, y;
        cin >> x >> y;
        
        int u = id_city[x];
        int v = id_city[y];
        int ancestor = lca(u, v);
        
        if(ancestor == -1){
            cout << "-1\n";
        }
        else{
            // Obter caminhos de ambas as cidades até o LCA
            vi path_u = get_path(u, ancestor);
            vi path_v = get_path(v, ancestor);
            reverse(all(path_v));
            vi fpath;
            fpath.reserve(sz(path_u) + sz(path_v) +1);
            fpath.insert(fpath.end(), all(path_u));
            fpath.pb(ancestor);
            fpath.insert(fpath.end(), all(path_v));
            
            string ans;
            vector<string> mp(id);
            for(auto &[name, idx] : id_city){
                mp[idx] = name;
            }
            for(auto &city_id : fpath){
                if(!mp[city_id].empty()){
                    ans += toupper(mp[city_id][0]);
                }
            }
            cout << ans << endl;
        }
    }
}

int32_t main()
{
    IOS;
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--){
        solve();
        if(tt) cout << endl;
    }
    return 0;
}