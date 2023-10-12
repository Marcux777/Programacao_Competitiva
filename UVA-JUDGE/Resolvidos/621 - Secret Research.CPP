#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "1" || s == "4" || s == "78")
        {
            cout << "+" << endl;
        }
        else
        {
            if (s.size() >= 2 && s.substr(s.size() - 2) == "35")
            {
                cout << "-" << endl;
            }
            else
            {
                if (s.size() >= 3 && s[0] == '9' && s[s.size() - 1] == '4')
                {
                    cout << "*" << endl;
                }
                else
                {
                    if (s.size() >= 3 && s.substr(0, 3) == "190")
                    {
                        cout << "?" << endl;
                    }
                    else
                    {
                        cout << "+" << endl;
                    }
                }
            }
        }
    }
    return 0;
}
