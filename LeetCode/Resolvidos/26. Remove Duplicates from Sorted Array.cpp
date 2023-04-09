#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        // remover os elementos duplicados
        auto iter = unique(nums.begin(), nums.end());
        nums.erase(iter, nums.end());
        return nums.size();
    }
};

int main()
{
    vector<int> v = {1,1,2};
    Solution x;
    cout << x.removeDuplicates(v) << endl;
}