#include <bits/stdc++.h>

using namespace std;

bool MaiorTam(string s1, string s2)
{
    return s1.size() > s2.size();
}

int main()
{
    int t;
    string s, palavra;
    vector<string> v;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        getline(cin, s);
        stringstream ss(s);
        while (ss >> palavra)
        {
            v.push_back(palavra);
        }

        stable_sort(v.begin(), v.end(), MaiorTam);

        for (auto it = v.begin(); it != v.end(); it++)
        {
            if (it == v.end() - 1)
            {
                cout << *it << endl;
            }
            else
            {
                cout << *it << " ";
            }
        }
        s.clear();
        v.clear();
    }
}