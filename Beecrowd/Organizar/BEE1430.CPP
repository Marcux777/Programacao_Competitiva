#include <iostream>
#include <string>
#include <math.h>
#include <map>

using namespace std;

map<char, double> mp;

double sum(char a)
{
    mp['W'] = 1.0;
    mp['H'] = 1.0 / 2.0;
    mp['Q'] = 1.0 / 4.0;
    mp['E'] = 1.0 / 8.0;
    mp['S'] = 1.0 / 16.0;
    mp['T'] = 1.0 / 32.0;
    mp['X'] = 1.0 / 64.0;
    auto it = mp.find(a);
    return it->second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    // freopen("saida.txt", "w", stdout);
    while (getline(cin, s) && s != "*")
    {
        double soma = 0.0, c = 0;
        for (int i = 0; s[i]; i++)
        {
            if (s[i] != '/')
            {
                soma += sum(s[i]);
            }
            else
            {
                if (soma == 1.0)
                {
                    c++;
                    soma = 0.0;
                }
                else
                {
                    soma = 0.0;
                }
            }
        }
        cout << c << endl;
    }
}