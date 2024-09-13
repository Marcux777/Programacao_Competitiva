#include <bits/stdc++.h>

using namespace std;

int main()
{
    string meio;
    int h, z, l;
    cin >> h >> z >> l;
    if (h > z)
    { // h é mais velho que z
        if (h > l)
        { // h é o mais velho de todos
            if (z > l)
            { // luizinho é o mais novo de todos
                meio = "zezinho";
            }
            else
            {
                meio = "luisinho";
            }
        }
        else
        {
            meio = "huguinho";
        }
    }
    else
    { // z é mais velho que h
        if (z > l)
        { // z é o mais velho
            if (h > l)
            { // l é o mais novo
                meio = "huguinho";
            }
            else
            {
                meio = "luisinho";
            }
        }
        else
        {
            meio = "zezinho";
        }
    }
    cout << meio << endl;
}
