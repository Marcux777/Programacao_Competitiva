#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cons, n;
    string str;
    bool dif;
    cin >> n;
    while (n--)
    {
        cons = 0;
        cin >> str;
        dif = false;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' && str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U')
            {
                cons++;
                if (cons >= 3)
                {
                    dif = true;
                }
            }
            else
            {
                cons = 0;
            }
        }
        if (!dif)
        {
            cout << str << " eh facil" << endl;
        }
        else
        {
            cout << str << " nao eh facil" << endl;
        }
    }
}
