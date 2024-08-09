#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;

class DSU
{
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n)
    {
        parent.assign(n, -1);
        rank.assign(n, 1);
    }

    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2])
            {
                parent[s2] = s1;
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};

int kruskal_mst(){
    int n = adj.size();
    int ans = 0;
    DSU s(n);

    sort(adj.begin(), adj.end());

    for(auto edge : adj){
        int x = edge[1], y = edge[2], w = edge[0];

        if(s.find(x) != s.find(y)){
            s.unite(x,y);
            ans += w;
        }
    }

    return ans;

}

/*
Entrada Exemplo:

4 5
0 1 10
1 3 15
2 3 4
2 0 6
0 3 5

Saida Esperada:

19

*/

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        adj.push_back({w, x, y});
    }

    cout << kruskal_mst() << endl;
}

