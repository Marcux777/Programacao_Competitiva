#include <bits/stdc++.h>
using namespace std;

// Topological sort

// https://www.geeksforgeeks.org/generate-lexicographically-smallest-permutation-of-1-to-n-where-elements-follow-given-relation/

/*Entre as sequências P que são permutações de (1, 2, ..., N) e que
satisfazem a condição abaixo, encontre a sequência lexicograficamente menor.

Para cada i = 1, ..., M, o elemento Aᵢ aparece antes do elemento Bᵢ em P.

Se não houver tal P, imprima -1.*/

vector<int> Permute(int n, int m, vector<pair<int, int>> &arr)
{
    vector<int> ans;
    vector<int> indegree(n);
    vector<vector<int>> out(n);

    for (int i = 0; i < m; i++)
    {
        int a = arr[i].first;
        int b = arr[i].second;
        a--;
        b--;

        indegree[b] = indegree[b] + 1;

        out[a].push_back(b);
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; ++i)
    {
        if (indegree[i] == 0)
        {
            pq.push(i);
        }
    }

    while (!pq.empty())
    {

        int i = pq.top();
        pq.pop();

        ans.push_back(i + 1);

        for (int j : out[i])
        {
            indegree[j] -= 1;
            if (indegree[j] == 0)
            {
                pq.push(j);
            }
        }
    }

    if (ans.size() != n)
    {
        return {-1};
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> graph(m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[i] = {x, y};
    }
    for (auto i : Permute(n, m, graph))
    {
        cout << i << " ";
    }
    cout << endl;
}