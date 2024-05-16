#include <bits/stdc++.h>

using namespace std;

#define int long long
#define IOS                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(0)
#define pb push_back
#define all(v) v.begin(), v.end()
#define f first
#define s second
#define Unique(v) \
  sort(all(v));   \
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

const int MAX_CITIES = 10000;
const int MAX_TIME = 600; // 10 horas em minutos

vvi dist;

struct Node
{
  int city;
  int gScore; // Custo do caminho até o nó atual
  int hScore; // Heurística para o nó objetivo
  int fScore; // gScore + hScore
  int parent; // ID do nó pai
};

// Função para comparar nós por fScore
struct CompareNodes
{
  bool operator()(const Node &a, const Node &b)
  {
    return a.fScore > b.fScore; // Usar > para priority_queue que é max por padrão
  }
};

// Função para reconstruir o caminho
vector<int> reconstructPath(map<int, int> &cameFrom, int current)
{
  vector<int> path;
  while (current != -1)
  {
    path.push_back(current);
    current = cameFrom[current];
  }
  reverse(path.begin(), path.end());
  return path;
}

// Função para calcular a heurística (implemente sua própria função heurística aqui)
int calculateHeuristic(int city, int goal)
{
  return dist[city][goal];
}

// Algoritmo A*
vector<int> aStar(vector<vector<pair<int, int>>> &graph, set<int> &hotels, int start, int goal)
{
  priority_queue<Node, vector<Node>, CompareNodes> openSet;
  map<int, int> cameFrom;
  map<int, int> gScore;
  for (int i = 0; i < MAX_CITIES; ++i)
  {
    gScore[i] = INF;
  }
  gScore[start] = 0;

  openSet.push({start, 0, calculateHeuristic(start, goal), 0, -1});

  while (!openSet.empty())
  {
    Node current = openSet.top();
    openSet.pop();

    if (current.city == goal)
    {
      return reconstructPath(cameFrom, current.city);
    }

    for (auto &edge : graph[current.city])
    {
      int neighbor = edge.first;
      int travelTime = edge.second;

      if (travelTime > MAX_TIME || hotels.find(neighbor) == hotels.end())
        continue; // Restrição de tempo e hotel

      int tentativeGScore = current.gScore + travelTime;
      if (tentativeGScore < gScore[neighbor])
      {
        cameFrom[neighbor] = current.city;
        gScore[neighbor] = tentativeGScore;
        int hScore = calculateHeuristic(neighbor, goal);
        openSet.push({neighbor, tentativeGScore, hScore, tentativeGScore + hScore, current.city});
      }
    }
  }
  return {}; // Nenhum caminho encontrado
}

void solve()
{
  //freopen("saida.txt", "w", stdout);
  int n, m, x;
  while (cin >> n && n)
  {
    vector<vector<pair<int, int>>> graph(n+1);
    dist.assign(n+1, vi(n+1, INF));
    int h;
    set<int> hotels;
    cin >> h;
    rep(i, 0, h)
    {
      cin >> x;
      hotels.insert(x);
    }
    cin >> m;
    rep(i, 0, m)
    {
      int u, v, w;
      cin >> u >> v >> w;
      dist[u][v] = w;
      dist[v][u] = w;
      graph[u].pb({v, w});
      graph[v].pb({u, w});
    }
    vi v = aStar(graph, hotels, 1, n);
    for (auto &node : v)
    {
      cout << node << endl;
    }
  }
}

int32_t main()
{
  IOS;
  int tt = 1;
  while (tt--)
    solve();
  return 0;
}