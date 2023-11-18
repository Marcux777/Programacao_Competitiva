#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

#define vi vector<int>
#define vll vector<ll>
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()

using namespace std;

const ll inf = 1e18;
struct Node
{
    Node *leftNode = 0, *rightNode = 0;
    int lo, hi;
    ll mset = inf, madd = 0, val = 0;
    Node(int lo, int hi) : lo(lo), hi(hi) {} // Large interval of -inf
    Node(vector<ll> &v, int lo, int hi) : lo(lo), hi(hi)
    {
        if (lo + 1 < hi)
        {
            int mid = lo + (hi - lo) / 2;
            leftNode = new Node(v, lo, mid);
            rightNode = new Node(v, mid, hi);
            val = leftNode->val + rightNode->val;
        }
        else
            val = v[lo];
    }
    // consultar a soma dos valores em um intervalo.
    ll query(int L, int R)
    {
        if (R <= lo || hi <= L)
            return 0;
        if (L <= lo && hi <= R)
            return val;
        push();
        return leftNode->query(L, R) + rightNode->query(L, R);
    }
    // definir os valores em um intervalo.
    void set(int L, int R, ll x)
    {
        if (R <= lo || hi <= L)
            return;
        if (L <= lo && hi <= R)
            mset = val = x, madd = 0;
        else
        {
            push(), leftNode->set(L, R, x), rightNode->set(L, R, x);
            val = leftNode->val + rightNode->val;
        }
    }
    // adicionar um valor a todos os valores em um intervalo.
    void add(int L, int R, ll x)
    {
        if (R <= lo || hi <= L)
            return;
        if (L <= lo && hi <= R)
        {
            if (mset != inf)
                mset += x;
            else
                madd += x;
            val += x;
        }
        else
        {
            push(), leftNode->add(L, R, x), rightNode->add(L, R, x);
            val = leftNode->val + rightNode->val;
        }
    }
    void push()
    {
        if (!leftNode)
        {
            int mid = lo + (hi - lo) / 2;
            leftNode = new Node(lo, mid);
            rightNode = new Node(mid, hi);
        }
        if (mset != inf)
            leftNode->set(lo, hi, mset), rightNode->set(lo, hi, mset), mset = inf;
        else if (madd)
            leftNode->add(lo, hi, madd), rightNode->add(lo, hi, madd), madd = 0;
    }
};

// A estrutura HLD implementa a decomposição pesada-leve.
// Se VALS_EDGES for true, isso significa que os valores estão associados às arestas da árvore. Em outras palavras, cada aresta da árvore tem um valor associado a ela.
// Se VALS_EDGES for false, isso significa que os valores estão associados aos nós da árvore. Ou seja, cada nó da árvore tem um valor associado a ele.
template <bool VALS_EDGES>
struct HLD
{
    int N, tim = 0;
    vector<vi> adj;
    vi par, siz, depth, rt, pos;
    Node *tree;

    // Construtor: inicializa as variáveis e começa a construção da decomposição.
    HLD(vector<vi> adj_)
        : N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
          rt(N), pos(N), tree(new Node(0, N))
    {
        dfsSz(0);
        dfsHld(0);
    }

    // Função para calcular o tamanho de cada subárvore.
    void dfsSz(int v)
    {
        if (par[v] != -1)
            adj[v].erase(find(all(adj[v]), par[v]));
        for (int &u : adj[v])
        {
            par[u] = v, depth[u] = depth[v] + 1;
            dfsSz(u);
            siz[v] += siz[u];
            if (siz[u] > siz[adj[v][0]])
                swap(u, adj[v][0]);
        }
    }

    // Função para construir a decomposição pesada-leve.
    void dfsHld(int v)
    {
        pos[v] = tim++;
        for (int u : adj[v])
        {
            rt[u] = (u == adj[v][0] ? rt[v] : u);
            dfsHld(u);
        }
    }

    // Função para processar uma operação em todos os nós ao longo de um caminho.
    void process(int u, int v, function<void(int, int)> op)
    {
        for (; rt[u] != rt[v]; v = par[rt[v]])
        {
            if (depth[rt[u]] > depth[rt[v]])
                swap(u, v);
            op(pos[rt[v]], pos[v] + 1);
        }
        if (depth[u] > depth[v])
            swap(u, v);
        op(pos[u] + VALS_EDGES, pos[v] + 1);
    }

    // Função para modificar os valores ao longo de um caminho.
    void modifyPath(int u, int v, ll val)
    {
        process(
            u, v, [&](int l, int r)
            { tree->set(l, r, val); });
    }

    // Função para consultar a soma dos valores ao longo de um caminho.
    ll queryPath(int u, int v)
    {
        ll res = 0;
        process(
            u, v, [&](int l, int r)
            { res = res + tree->query(l, r); });
        return res;
    }
};

struct edge
{
    int u, v, w;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> adj(N);
    vector<edge> edges(N);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges[i] = {u, v, w};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    HLD<true> hld(adj);
    for (int i = 0; i < N - 1; i++)
    {
        hld.modifyPath(edges[i].u, edges[i].v, edges[i].w);
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int i, w;
            cin >> i >> w;
            i--;
            hld.modifyPath(edges[i].u, edges[i].v, w);
        }
        else
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            cout << hld.queryPath(u, v) << endl;
        }
    }
    return 0;
}