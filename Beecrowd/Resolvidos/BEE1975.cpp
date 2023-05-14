#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("saida.txt", "w", stdout);
    int p, a, r;
    while (cin >> p >> a >> r && p && a && r)
    {
        cin.ignore();
        map<string, int> mp;
        set<string> perolas;
        for (int i = 0; i < p; i++)
        {
            string perola;
            getline(cin, perola);
            perolas.insert(perola);
        }
        for (int i = 0; i < a; i++)
        {
            string nome;
            cin >> nome;

            auto it = mp.find(nome);
            if (it == mp.end())
            {
                mp[nome] = 0;
                cin.ignore();
                for (int j = 0; j < r; j++)
                {
                    string resp;
                    getline(cin, resp);
                    auto it = perolas.count(resp);
                    if (it)
                    {
                        mp[nome]++;
                    }
                }
            }
            else
            {
                cin.ignore();
                for (int j = 0; j < r; j++)
                {
                    string lixo;
                    getline(cin, lixo);
                }
            }
        }
        int maxCount = -1;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            maxCount = max(maxCount, it->second);
        }
        vector<string> v;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second == maxCount)
            {
                v.push_back(it->first);
            }
        }
        sort(v.begin(), v.end());

        for (int i = 0; i < (int)v.size(); i++)
        {
            cout << v[i];
            if (i < (int)v.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }
}
