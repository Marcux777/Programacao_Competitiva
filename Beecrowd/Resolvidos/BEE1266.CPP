#include <iostream>

using namespace std;

int main()
{
    int n;
    while (cin >> n && n)
    {
        int v[n];
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 0)
            {
                if (v[(i + 1) % n] == 0 && v[(i + 2) % n] == 0)
                {
                    v[(i + 1) % n] = 1;
                    c++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 0)
            {
                if (v[(i + 1) % n] == 0)
                {
                    v[(i + 1) % n] = 1;
                    c++;
                }
            }
        }
        cout << c << endl;
    }
}