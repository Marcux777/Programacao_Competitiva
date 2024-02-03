#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1e9
#define endl '\n'
#define f first
#define s second
#define all(x) (x).rbegin(), (x).rend() // obter um intervalo que abrange todo o contêiner
#define fi(x) find()
#define sz(x) ((int)(x).size()) // tamanho
#define pb push_back
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define vll vector<long long>
#define PI 3.14159265358979323846

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;

    int j, i;
    for (i = 1; i < n; i++)
    {
        while (v[i - 1] > v[i])
        {
            if (v[i - 1] < 0 && v[i] < 0)
            {
                for (j = 0; j < n; j++)
                {
                    v[i - 1] = min(v[i - 1], v[i - 1] + v[j]);
                }
            }
            else
            {
                for (j = 0; j < n; j++)
                {
                    v[i] = max(v[i], v[i] + v[j]);
                }
            }
        }
    }
    for (auto i : v)
    {
        cout << i << " ";
    }
}
