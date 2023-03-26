#include <iostream>
#include <string>

using namespace std;
int main()
{
    string s;
    bool r = false;
    cin >> s;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '1' && s[i + 1] == '3')
        {
            r = true;
        }
    }
    if (r)
    {
        cout << s << " es de Mala Suerte" << endl;
    }
    else
    {
        cout << s << " NO es de Mala Suerte" << endl;
    }
}
