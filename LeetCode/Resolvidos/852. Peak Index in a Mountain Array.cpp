#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return -1; // array não tem montanha
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] < arr[mid+1]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};

int main() {
    vector<int> arr = {0, 1, 2, 3, 4, 3, 1};
    Solution s;
    int peakIndex = s.peakIndexInMountainArray(arr);
    cout << "Peak index: " << peakIndex << endl;
    return 0;
}
