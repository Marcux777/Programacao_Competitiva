#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        for (auto it = 0; it < nums.size(); it++)
        {
            nums[it] *= nums[it];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-4, -1, 0, 3, 10};
    cout << "Vetor inicial: ";
    for (auto n : nums)
    {
        cout << n << " ";
    }
    vector<int> sortedSquares = s.sortedSquares(nums);

    cout << "\nVetor com quadrados ordenados: ";
    for (auto n : sortedSquares)
    {
        cout << n << " ";
    }

    return 0;
}
