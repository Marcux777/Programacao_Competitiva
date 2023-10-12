#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int sonars_n = ceil((n - 2) / 3.0);
        int sonars_m = ceil((m - 2) / 3.0);
        cout << sonars_n * sonars_m << endl;
    }

    return 0;
}
