#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size();
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }
        return lo;
    }
};

int main()
{
    Solution solution;

    // Criação do vetor de inteiros ordenado
    vector<int> nums = {1, 3, 5, 6};
    int target = 4;

    // Chamada da função searchInsert
    int result = solution.searchInsert(nums, target);

    // Imprime a posição de inserção do elemento no vetor
    cout << "Posição de inserção: " << result << endl;

    return 0;
}
