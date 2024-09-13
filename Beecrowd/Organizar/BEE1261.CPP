#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    // freopen("saida.txt", "w", stdout);
    int m, n;
    map<string, long int> mp;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        string palavra;
        long int d;
        cin >> palavra >> d;
        mp[palavra] = d;
    }
    string s;
    for (int i = 0; i < n; i++)
    {
        long int valor = 0;
        while (cin >> s && s != ".")
        {
            if (mp.count(s) > 0)
            {
                valor += mp[s];
            }
        }
        cout << valor << endl;
    }
}