#include <bits/stdc++.h>

using namespace std;

int find(const string &text, const string &pattern, int start)
{
    int n = text.size();
    int m = pattern.size();
    for (int i = start; i <= n - m; i++)
    {
        int j = 0;
        while (j < m && text[i + j] == pattern[j])
        {
            j++;
        }
        if (j == m)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("saida.txt", "w", stdout);
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string frase, palavra;

        string line;
        while (getline(cin, line) && line.empty())
            ;

        frase = line;

        while (getline(cin, line) && line.empty())
            ;

        palavra = line;

        vector<int> pos;
        frase = " " + frase + " ";
        palavra = " " + palavra + " ";
        int found = find(frase, palavra, 0);
        while (found != -1)
        {
            pos.push_back(found);
            found = find(frase, palavra, found + 1);
        }

        if (!pos.empty())
        {
            for (int i = 0; i < pos.size(); i++)
            {
                cout << pos[i];
                if (pos.size() > 1 && i < pos.size() - 1)
                {
                    cout << " ";
                }
            }
        }
        else
        {
            cout << -1;
        }
        cout << endl;
    }
    return 0;
}
