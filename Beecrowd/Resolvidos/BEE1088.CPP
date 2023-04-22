#include <iostream>
#include <vector>

using namespace std;

int merge_sort_and_count_inversions(vector<int> &arr, int l, int r)
{
    if (l == r)
    {
        return 0;
    }
    int mid = (l + r) / 2;

    int inversions = merge_sort_and_count_inversions(arr, l, mid) + merge_sort_and_count_inversions(arr, mid + 1, r);

    vector<int> tmp(r - l + 1);

    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            tmp[k++] = arr[i++];
        }
        else
        {
            tmp[k++] = arr[j++];
            inversions += mid - i + 1;
        }
    }
    while (i <= mid)
    {
        tmp[k++] = arr[i++];
    }
    while (j <= r)
    {
        tmp[k++] = arr[j++];
    }
    for (i = l, k = 0; i <= r; i++, k++)
    {
        arr[i] = tmp[k];
    }
    return inversions;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n && n != 0)
    {
        vector<int> perm(n);
        for (int i = 0; i < n; i++)
        {
            cin >> perm[i];
        }
        int inversions = merge_sort_and_count_inversions(perm, 0, n - 1);
        if (inversions % 2 == 0)
        {
            cout << "Carlos\n";
        }
        else
        {
            cout << "Marcelo\n";
        }
    }
    return 0;
}
