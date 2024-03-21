#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define endl '\n'

bool f(int n)
{
    if (n < 0) {
        return false;
    }
    
    for (int a = 0; a * a <= n; ++a) {
        int b_squared = n - a * a;
        
        if (b_squared >= 0 && sqrt(b_squared) == static_cast<int>(std::sqrt(b_squared))) {
            return true;
        }
    }
    
    return false;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    while (cin >> n)
    {
        cout << (f(n) ? "YES" : "NO") << endl;
    }
}