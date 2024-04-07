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
using namespace std;
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
// template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << ' ' << H; dbg_out(T...); }
// #define dbg(...) cerr<<"(" << #_VA_ARGS<<"):" , dbg_out(VA_ARGS_) , cerr << endl

int h, w;
vector<vector<char>> grid;
vector<vector<int>> medicines;

struct Cell
{
    int x, y, energy;
};

Cell start, goal;

bool isValid(int x, int y) {
    return x >= 0 && x < h && y >= 0 && y < w;
}

bool dfs(Cell cell)
{
    if (cell.x == goal.x && cell.y == goal.y)
        return true; // Chegou ao destino
    if (grid[cell.x][cell.y] == '#' || cell.energy <= 0)
        return false; // Obstáculo ou sem energia

    // Atualizar energia se estiver em uma célula com medicina
    if (medicines[cell.x][cell.y] != -1)
    {
        cell.energy = medicines[cell.x][cell.y];
        medicines[cell.x][cell.y] = -1;
    }

    grid[cell.x][cell.y] = '#'; // Marcar como visitado

    // Movimentos possíveis: cima, baixo, esquerda, direita e diagonais
    int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

    for (int i = 0; i < 8; ++i)
    {
        int nx = cell.x + dx[i];
        int ny = cell.y + dy[i];

        if (isValid(nx, ny) && dfs({nx, ny, cell.energy - 1}))
        {
            return true; // Caminho encontrado
        }
    }

    grid[cell.x][cell.y] = '.'; // Desmarcar para permitir outros caminhos
    return false;
}

void solve()
{
    cin >> h >> w;
    grid = vector<vector<char>>(h, vector<char>(w));
    medicines = vector<vector<int>>(h, vector<int>(w, -1));

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
                start = {i, j, 0};
            if (grid[i][j] == 'T')
                goal = {i, j, 0};
        }
    }

    int n, r, c, e;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> r >> c >> e;
        medicines[--r][--c] = e;
    }

    if (dfs(start))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
int32_t main()
{
    // IOS;
    int tt = 1;
    while (tt--)
        solve();
    return 0;
}