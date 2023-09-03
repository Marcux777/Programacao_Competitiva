#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, a;
        cin >> s;
        if (s.size() > 10)
        {
            a += s[0];
            int tam = s.size();
            a += to_string(tam - 2);
            a += s[tam - 1];
            cout << a << endl;
        }
        else
        {
            cout << s << endl;
        }
    }
}