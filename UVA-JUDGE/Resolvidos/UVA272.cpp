#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("saida.txt", "w", stdout);
    string line;
    bool open_quote = false;

    while (getline(cin, line))
    {
        for (char &c : line)
        {
            if (c == '"')
            {
                if (open_quote)
                {
                    cout << "''";
                }
                else
                {
                    cout << "``";
                }
                open_quote = !open_quote;
            }
            else
            {
                cout << c;
            }
        }

        cout << endl;
    }

    return 0;
}
