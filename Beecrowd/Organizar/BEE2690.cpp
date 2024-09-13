#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

vector<char> v[10];

int returnNum(char letra)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == letra)
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("saida.txt", "w", stdout);
    v[0] = {'G', 'Q', 'a', 'k', 'u'};
    v[1] = {'I', 'S', 'b', 'l', 'v'};
    v[2] = {'E', 'O', 'Y', 'c', 'm', 'w'};
    v[3] = {'F', 'P', 'Z', 'd', 'n', 'x'};
    v[4] = {'J', 'T', 'e', 'o', 'y'};
    v[5] = {'D', 'N', 'X', 'f', 'p', 'z'};
    v[6] = {'A', 'K', 'U', 'g', 'q'};
    v[7] = {'C', 'M', 'W', 'h', 'r'};
    v[8] = {'B', 'L', 'V', 'i', 's'};
    v[9] = {'H', 'R', 'j', 't'};
    int t;
    cin >> t;
    //cin.ignore();
    while (t--)
    {
        char frase[100];
        string result = "";
        scanf(" %[^\n]", frase);
        for (int i = 0; frase[i] && result.size() < 12; i++)
        {
            if (isalpha(frase[i]))
            {
                result += to_string(returnNum(frase[i]));
            }
        }
        cout << result << endl;
    }
}