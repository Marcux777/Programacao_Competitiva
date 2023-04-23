#include <iostream>
using namespace std;
int main()
{
    int n, h[100], num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    if (n == 2)
    {
        if (h[0] == h[1])
        {
            num = 0;
        }
        else
        {
            num = 1;
        }
    }
    else
    {
        num = 1;
        for (int i = 2; i < n; i++)
        {
            if (h[i - 2] > h[i - 1] && h[i] > h[i - 1])
            {
                num = 1;
            }
            else if (h[i - 1] > h[i - 2] && h[i - 1] > h[i])
            {
                num = 1;
            }
            else
            {
                num = 0;
            }
        }
    }
    cout << num << endl;
    return 0;
}