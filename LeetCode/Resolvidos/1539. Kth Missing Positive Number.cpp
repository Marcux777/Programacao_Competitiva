#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int l = 0, r = arr.size();
        while (r > l)
        {
            int mid = (l + r) / 2;
            if (arr[mid] - mid - 1 < k)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l + k;
    }
};

int main()
{
    Solution s;
    vector<int> arr{2, 3, 4, 7, 11};
    int k = 5;
    cout << s.findKthPositive(arr, k) << endl;
    return 0;
}
