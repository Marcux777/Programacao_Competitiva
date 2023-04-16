#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    long long int arrangeCoins(long long int n)
    {
        long long int x = (-1 + sqrt(1 + 8 * n)) / 2;
        return x;
    }
};

int main()
{
    Solution sol;
    long long int n = 10;
    long long int result = sol.arrangeCoins(n);
    cout << "Para " << n << " moedas temos " << result << " pilhas completas." << endl;
    return 0;
}
