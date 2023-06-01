#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    bool igual = true;
    for (int i = 0; i < n && igual; i++)
    {
        if (s[i] == t[i] || (s[i] == '1' && t[i] == 'l') || (s[i] == 'l' && t[i] == '1') || (s[i] == '0' && t[i] == 'o') || (s[i] == 'o' && t[i] == '0'))
        {
        }
        else
        {
            igual = false;
        }
    }
    if (igual)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}