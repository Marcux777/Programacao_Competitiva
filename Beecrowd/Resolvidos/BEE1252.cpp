#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

bool customSort(int a, int b)
{
    if (a % m != b % m)
    {
        return a % m < b % m;
    }
    else
    {
        if (a % 2 == 0 && b % 2 == 0)
        {
            return a < b;
        }
        else
        {
            if (a % 2 != 0 && b % 2 != 0)
            {
                return a > b;
            }
            else
            {
                return a % 2 != 0;
            }
        }
    }
}

int main()
{
    //freopen("saida.txt", "w", stdout);
    while (cin >> n >> m && n && m)
    {
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end(), customSort);
        cout << n << " " << m << endl;
        for (int i = 0; i < n; i++)
        {
            cout << nums[i] << endl;
        }
    }
    cout << 0 << ' ' << 0 << endl;
    return 0;
}