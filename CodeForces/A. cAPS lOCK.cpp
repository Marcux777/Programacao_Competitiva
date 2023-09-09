#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str, s;
    cin >> str;

    bool allUpperCase = true;

    for (int i = 1; i < str.size(); i++)
    {
        if (islower(str[i]))
        {
            allUpperCase = false;
        }
    }

    if (allUpperCase)
    {
        for (char c : str)
        {
            if (islower(c))
            {
                s += toupper(c);
            }
            else
            {
                s += tolower(c);
            }
        }
    }
    else
    {
        s = str;
    }

    cout << s << endl;

    return 0;
}
