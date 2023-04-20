#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int tam = nums.size();
        mergeSort(nums, 0, tam - 1);
    }
    void mergeSort(vector<int> &arr, int l, int r)
    {
        if (l < r)
        {
            int m = l + (r - l) / 2;

            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);

            merge(arr, l, m, r);
        }
    }
    void merge(vector<int> &arr, int l, int m, int r)
    {
        int i, j, k;

        vector<int> v(r - l + 1);

        i = l;
        j = m + 1;
        k = 0;
        while (i <= m)
        {
            if (arr[i] == 0)
            {
                i++;
            }
            else
            {
                v[k] = arr[i];
                k++;
                i++;
            }
        }
        while (i <= m)
        {
            if (arr[i] == 0)
            {
                i++;
            }
            else
            {
                v[k++] = arr[i++];
            }
        }
        while (j <= r)
        {
            if (arr[j] == 0)
            {
                j++;
            }
            else
            {
                v[k++] = arr[j++];
            }
        }
        for (i = l; i <= r; i++)
        {
            arr[i] = v[i - l];
        }
    }
};

int main()
{
    Solution solucao;
    std::vector<int> nums = {0, 2, 0, 1, 0, 3, 12};

    std::cout << "Vetor original: ";
    for (auto num : nums)
    {
        std::cout << num << " ";
    }
    cout << endl;

    solucao.moveZeroes(nums);

    std::cout << "Vetor ordenado: ";
    for (auto num : nums)
    {
        std::cout << num << " ";
    }

    return 0;
}
