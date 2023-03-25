#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<string, int> mp;
    set<string> mortos;
    string assassino, morreu;
    while (cin >> assassino)
    {
        cin >> morreu;
        mp[assassino]++;
        mortos.insert(morreu);
    }
    for (string i : mortos)
    {
        auto it = mp.find(i);
        if (it != mp.end())
        { // mataram um assassino
            mp.erase(i);
        }
    }

    cout << "HALL OF MURDERERS\n";
    for (auto i : mp)
    {
        cout << i.first << " " << i.second << endl;
    }
}