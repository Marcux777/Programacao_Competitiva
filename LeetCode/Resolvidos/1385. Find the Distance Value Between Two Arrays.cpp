#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        int count = 0;
        for (int num1 : arr1)
        {
            bool is_valid = true;
            for (int num2 : arr2)
            {
                if (abs(num1 - num2) <= d)
                {
                    is_valid = false;
                    break;
                }
            }
            if (is_valid)
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    vector<int> arr1 = {4, 5, 8};
    vector<int> arr2 = {10, 9, 1, 8};
    int d = 2;
    Solution sol;
    int distance_value = sol.findTheDistanceValue(arr1, arr2, d);
    cout << "Distance value: " << distance_value << endl; // Output: 2
    return 0;
}
