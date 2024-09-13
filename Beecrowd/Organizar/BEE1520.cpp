#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int busca_binaria_menorId(vector<int> &v, int target)
{
    int l = 0, r = v.size() - 1;
    int pos = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (v[mid] == target)
        {
            pos = mid;
            r = mid - 1;
        }
        else
        {
            if (v[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
    }
    return pos;
}

int busca_binaria_maiorId(vector<int> &v, int target)
{
    int l = 0, r = v.size() - 1;
    int pos = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (v[mid] == target)
        {
            pos = mid;
            l = mid + 1;
        }
        else
        {
            if (v[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
    }
    return pos;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("saida.txt", "w", stdout);
    int n;
    while (cin >> n)
    {
        vector<int> v;
        while (n--)
        {
            int x, y;
            cin >> x >> y;

            for (int i = x; i <= y; i++)
            {
                v.push_back(i);
            }
        }
        sort(v.begin(), v.end());
        int num;
        cin >> num;
        int l = busca_binaria_menorId(v, num);
        int r = busca_binaria_maiorId(v, num);
        if (l != -1 && r != -1)
        {
            cout << num << " found from " << l << " to " << r << endl;
        }
        else
        {
            cout << num << " not found" << endl;
        }
    }
}