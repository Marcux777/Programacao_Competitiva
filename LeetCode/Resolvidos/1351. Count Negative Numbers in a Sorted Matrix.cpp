#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int tam = grid.size();
        int soma = 0;
        for (int i = 0; i < tam; i++)
        {
            soma += QuantNegativos(grid[i]);
        }
        return soma;
    }
    int QuantNegativos(vector<int> &v)
    {
        int l = 0, r = v.size();
        int Neg = 0;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (v[mid] < 0)
            {
                r--;
                Neg++;
            }
            else
            {
                if (v[mid] >= 0)
                {
                    l = mid + 1;
                }
            }
        }
        return Neg;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> v = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
    cout << sol.countNegatives(v) << endl;
}