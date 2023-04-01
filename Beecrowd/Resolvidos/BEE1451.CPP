#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
        
    string line;
    //freopen("saida.txt", "w", stdout);
    while (getline(cin, line))
    {
        vector<char> text;
        int cursor = 0;
        for (char c : line)
        {
            if (c == '[')
            {
                cursor = 0;
            }
            else
            {
                if (c == ']')
                {
                    cursor = text.size();
                }
                else
                {
                    text.insert(text.begin() + cursor, c);
                    cursor++;
                }
            }
        }
        for (int i = 0; i < text.size(); i++)
        {
            cout << text[i];
        }
        cout << endl;
    }
    return 0;
}
