#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int l = 0, r = numbers.size() - 1;
        while (l <= r)
        {
            if (numbers[l] + numbers[r] == target)
            {
                return {l + 1, r + 1};
            }
            else
            {
                if (numbers[l] + numbers[r] > target)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return {-1, -1};
    }
};

int main()
{
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    Solution s;
    vector<int> result = s.twoSum(numbers, target);
    cout << "Indices dos elementos que somados resultam em " << target << ": " << result[0] << " e " << result[1] << endl;
    return 0;
}
