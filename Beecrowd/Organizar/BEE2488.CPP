#include <iostream>
#include <cmath>
#include <iomanip>
#include <map>
using namespace std;


const int INF = 0x3F3F3F3F;
const int MAXN = 10010;
const int MAXT = 40040;

int N, P, cnt = 1;
int tree[MAXT], v[MAXN];
map<pair<int, int>, int> mapa;

void build_tree(int node, int i, int j) {
    if (i == j) {
        tree[node] = v[i];
        return;
    }
    int L = node * 2, R = node * 2 + 1, mid = (i + j) / 2;
    build_tree(L, i, mid);
    build_tree(R, mid + 1, j);
    tree[node] = max(tree[L], tree[R]);
}

int query_tree(int node, int i, int j, int a, int b) {
    if (b < i || a > j)
        return -INF;
    if (a <= i && j <= b)
        return tree[node];
    int L = node * 2, R = node * 2 + 1, mid = (i + j) / 2;
    int SL = query_tree(L, i, mid, a, b);
    int SR = query_tree(R, mid + 1, j, a, b);
    return max(SL, SR);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	//freopen("saida.txt", "w", stdout);
    cin >> N >> P;
    pair<int, int> aux, last;
    
    cin >> aux.first >> aux.second;
    mapa[aux] = cnt++;
    last = aux;
    
    for (int i = 1; i < N; i++) {
        cin >> aux.first >> aux.second;
        v[cnt] = abs((aux.first - last.first)) * abs((aux.first - last.first)) +
                 abs((aux.second - last.second)) * abs((aux.second - last.second));
        mapa[aux] = cnt++;
        last = aux;
    }

    build_tree(1, 1, N);

    while (P--) {
        cin >> aux.first >> aux.second;
        cin >> last.first >> last.second;
        int a = mapa[aux], b = mapa[last];
        if (a > b)
            swap(a, b);
        a++;
        double ans = sqrt(query_tree(1, 1, N, a, b));
        if(isnan(ans)){
            ans = 0.0;
        }
        cout << fixed << setprecision(2) << ans << endl;
    }

    return 0;
}
