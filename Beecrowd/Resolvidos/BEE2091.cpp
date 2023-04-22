#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("saida.txt", "w", stdout);
    int n;
    while (cin >> n && n)
    {
        long long int solitario;

        map<long long int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> solitario;
            auto it = mp.find(solitario);
            if (it != mp.end())
            {
                it->second++;
            }
            else
            {
                mp[solitario] = 1;
            }
        }
        for (auto it : mp)
        {
            if(it.second % 2){
                cout << it.first<< endl;
            }
        }
    }
}