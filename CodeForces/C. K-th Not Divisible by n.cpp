#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        cout << k + (k - 1) / (n - 1) << endl;
    }

    return 0;
}
