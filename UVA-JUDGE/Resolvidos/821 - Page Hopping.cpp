#include <bits/stdc++.h>

using namespace std;
#define endl '\n';

#define inf 1000

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int caze = 0;
    int n, m;
    cin >> n >> m;
    while ((n || m))
    {
        vector<vector<int>> dist(101, vector<int>(101, inf));
        for (int i = 0; i <= 100; i++)
            dist[i][i] = 0;
        double soma = 0.0;
        int count = 0;
        while (n || m)
        {
            dist[n][m] = 1;
            cin >> n >> m;
        }
        for (int k = 0; k <= 100; k++)
        {
            for (int i = 0; i <= 100; i++)
            {
                for (int j = 0; j <= 100; j++)
                {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        for (int i = 0; i <= 100; i++)
        {
            for (int j = 0; j <= 100; j++)
            {
                if (i != j && dist[i][j] != inf)
                {
                    soma += dist[i][j];
                    count++;
                }
            }
        }
        cout << "Case " << ++caze << ": average length between pages = ";
        cout << fixed << setprecision(3);
        cout << soma / count;
        cout << " clicks\n";
        cin >> n >> m;
    }
}