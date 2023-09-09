#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int diff = abs(a - b);
        int moves = ceil((double)diff / (2 * c));
        cout << moves << endl;
    }
    return 0;
}