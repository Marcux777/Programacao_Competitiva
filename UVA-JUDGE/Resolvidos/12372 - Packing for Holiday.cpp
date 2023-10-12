#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("saida.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << "Case " << i + 1 << ": ";
        if (a > 20 || b > 20 || c > 20)
        {
            cout << "bad\n";
        }
        else
        {
            cout << "good\n";
        }
    }
}
