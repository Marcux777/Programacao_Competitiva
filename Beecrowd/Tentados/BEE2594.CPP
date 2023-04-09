#include <bits/stdc++.h>

using namespace std;

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //freopen("saida.txt", "w", stdout);
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> pos;
        string frase, palavra;

        getline(cin, frase);

        getline(cin, palavra);
        for (int i = 0; i < frase.size(); i++)
        {
            bool dento = true;
            int k = 0, j = i;
            if (j > 0 && isalpha(frase[j - 1]))
            {
                dento = false;
            }
            while (k < palavra.size() && j < frase.size() && frase[j] == palavra[k])
            {
                k++;
                j++;
            }
            if (j + 1 < frase.size())
            {
                if (isalpha(frase[j]))
                {
                    dento = false;
                }
            }

            if (dento && k == palavra.size())
            {
                pos.push_back(i);
            }
        }
        if (!pos.empty())
        {
            for (int i = 0; i < pos.size(); i++)
            {
                cout << pos[i];
                if (i < pos.size() - 1)
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
