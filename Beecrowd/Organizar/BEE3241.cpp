#include <iostream>

using namespace std;

int main()
{
    string a;
    int n;
    int b, c;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        b = c = 0;
        cin >> a;
        if (a[0] == 'P')
        {
            cout << "skipped" << endl;
        }
        else
        {
            int j, k;
            for (j = 0; a[j] != '+'; j++)
            {
                b = b * 10 + a[j] - '0';
            }
            for (k = j + 1; k < a.size(); k++)
            {
                c = c * 10 + a[k] - '0';
            }
            cout << b + c << endl;
        }
        a.clear();
    }
}