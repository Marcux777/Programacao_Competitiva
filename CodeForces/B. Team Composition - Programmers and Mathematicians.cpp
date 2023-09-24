#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int a, b;
        cin >> a >> b;

        long long int times = min(a, b);
        if (a + b < times * 4)
        {
            times = (a + b) / 4;
        }
        cout << times << endl;
    }
}
