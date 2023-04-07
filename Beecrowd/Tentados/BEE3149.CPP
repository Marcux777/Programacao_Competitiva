#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <locale.h>


using namespace std;

bool comp(pair<int, string>& a, pair<int, string>& b)
{
    return a.first < b.first;
}

int ToMin(string a)
{
    int s = 0;
    if (a[0] == '0' && a[1] == '0')
    {
        s += 1440;
    }
    s += (((a[0] - '0') * 10) + (a[1] - '0')) * 60 + (a[3] - '0') * 10 + a[4] - '0';
    //cout << s << endl;
    return s;
}

int main()
{
    setlocale(LC_ALL, "pt_BR.utf8");
    //freopen("saida.txt", "w", stdout);
    vector<pair<int, string>> v;
    vector<pair<int, string>> final;
    int horaS;
    int temp, n;
    cin >> temp >> n;
    while (n--)
    {
        string horario, nome;
        cin >> horario >> nome;
        horaS = ToMin(horario);
        v.push_back({horaS, nome});
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (abs(v[i].first - 1440) <= temp)
        {
            final.push_back(v[i]);
        }
    }
    sort(final.begin(), final.end(), comp);
    for (auto it : final)
    {
        cout << it.second << endl;
    }
}