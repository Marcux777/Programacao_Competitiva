#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool compareBySecond(const pair<char, int> &a, const pair<char, int> &b)
{
    if(a.second != b.second){
        return a.second < b.second;
    }
    return (int)a.first > (int)b.first; 
}

vector<pair<char, int>> sortMapByValue(const map<char, int> &myMap)
{
    vector<pair<char, int>> vec(myMap.begin(), myMap.end());

    sort(vec.begin(), vec.end(), compareBySecond);

    return vec;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("saida.txt", "w", stdout);
    string str;
    bool aux = false;

    while (getline(cin, str))
    {
        if (aux)
        {
            cout << '\n';
        }
        aux = true;
        map<char, int> mapa;
        for (int i = 0; i < str.size(); i++)
        {
            
            auto it = mapa.find(str[i]);
            if (it != mapa.end())
            {
                it->second++;
            }
            else
            {
                mapa[str[i]] = 1;
            }
        }
        vector<pair<char, int>> final = sortMapByValue(mapa);

        for (auto it = final.begin(); it != final.end(); it++)
        {
            cout << (int)it->first << " " << it->second << endl;
        }
    }
}