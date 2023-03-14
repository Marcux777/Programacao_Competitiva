#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    //freopen("saida.txt", "w", stdout);
    string rnaa;
    while (cin >> rnaa)
    {
        stack<char> s;
        int links = 0;
        for (char c : rnaa)
        {
            if (s.empty())
            {
                s.push(c);
            }
            else
            {
                if ((c == 'S' && s.top() == 'B') || (c == 'B' && s.top() == 'S'))
                {
                    s.pop();
                    links += 1;
                }
                else
                {
                    if ((c == 'C' && s.top() == 'F') || (c == 'F' && s.top() == 'C'))
                    {
                        s.pop();
                        links += 1;
                    }
                    else
                    {
                        s.push(c);
                    }
                }
            }
        }
        cout << links << endl;
    }
    return 0;
}
