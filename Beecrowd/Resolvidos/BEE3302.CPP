#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v;
    int a, n;
    cin >> n;
    while (n--)
    {
        cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << "resposta " << i + 1 << ": " << v[i] << endl;
    }
}
