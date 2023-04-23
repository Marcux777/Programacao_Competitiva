#include <iostream>
using namespace std;
int main()
{
    int n, pico;
    long long int h[10001];
    cin >> n;
    while (n != 0)
    {
        pico = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        for (int i = 1; i <= n; i++)
        {
            h[n] = h[0];
            h[n + 1] = h[1];
            if (h[i] < h[i - 1] && h[i] < h[i + 1])
            {
                pico++;
            }
            else if (h[i] > h[i - 1] && h[i] > h[i + 1])
            {
                pico++;
            }
        }
        cout << pico << endl;
        cin >> n;
    }
}