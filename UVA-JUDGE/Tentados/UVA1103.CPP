#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

string toBin(char c)
{
    string str;
    int a = c - '0';
    if (c >= 'a' && c <= 'a')
    {
        a = 10 + c - 'a';
    }
    str += (bitset<4>(a)).to_string();
    for(int i = 0; i <= 2 && str[0] == '0'; i++){
        str.erase(str.begin());
    }
    return str;
}

string v[200];

int main()
{
    freopen("saida.txt", "w", stdout);
    int h, w;
    while (cin >> h >> w && h && w)
    {
        string str;
        for (int i = 0; i < h; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < h; i++)
        {

            for (auto c : v[i])
            {
                str += toBin(c);
            }

            cout << str << endl;
            str.clear();
        }
    }
}