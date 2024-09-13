#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> fases;
    vector<pair<int, pair<int, int>>> competidores;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int r, e;
        cin >> r >> e;
        competidores.push_back(make_pair(i+1, make_pair(r, e)));
        fases.push_back(1);
    }

    cin.ignore();
    string s;
    getline(cin, s);
    int len_s = s.size();

    while (competidores.size() > 1)
    {
        vector<pair<int, pair<int, int>>> proximos;
        int k = 0;
        for (int i = 0; i < competidores.size(); i += 2)
        {
            pair<int, int> c1 = competidores[i].second;
            pair<int, int> c2 = competidores[i + 1].second;
            int time_c1 = c1.first + c1.second * len_s;
            int time_c2 = c2.first + c2.second * len_s;

            if (time_c1 < time_c2 || (time_c1 == time_c2 && competidores[i].first < competidores[i + 1].first))
            {
                proximos.push_back(competidores[i]);
                fases[competidores[i].first - 1] = max(fases[competidores[i].first - 1], fases[competidores[i + 1].first - 1] + 1);
            }
            else
            {
                proximos.push_back(competidores[i + 1]);
                fases[competidores[i + 1].first - 1] = max(fases[competidores[i + 1].first - 1], fases[competidores[i].first - 1] + 1);
            }
            k++;
        }
        competidores = proximos;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            cout << fases[i];
        }
        else
        {
            cout << fases[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
