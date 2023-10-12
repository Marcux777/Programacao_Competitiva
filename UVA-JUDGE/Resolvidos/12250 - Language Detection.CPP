#include <bits/stdc++.h>
#include <map>

using namespace std;

int main()
{
    map<string, string> mp;

    mp["HELLO"] = "ENGLISH";
    mp["HOLA"] = "SPANISH";
    mp["HALLO"] = "GERMAN";
    mp["BONJOUR"] = "FRENCH";
    mp["CIAO"] = "ITALIAN";
    mp["ZDRAVSTVUJTE"] = "RUSSIAN";

    string s;
    int cont = 0;
    while (cin >> s && s != "#")
    {
        auto it = mp.find(s);
        cout << "Case " << ++cont << ": ";
        if (it != mp.end())
        {
            cout << it->second << endl;
        }
        else
        {
            cout << "UNKNOWN" << endl;
        }
    }
}