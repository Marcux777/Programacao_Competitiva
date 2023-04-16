#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        int r = nums.size();
        int x = 1;
        while (x <= r)
        {
            int cont = 0;
            for (int i = 0; i < r; i++)
            {
                if (nums[i] >= x)
                {
                    cont++;
                }
            }
            if (cont == x)
            {
                return x;
            }
            else
            {
                x++;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 5};
    int result = s.specialArray(nums);
    cout << "Result: " << result << endl;
    return 0;
}
