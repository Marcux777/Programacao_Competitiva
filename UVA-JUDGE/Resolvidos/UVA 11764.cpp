#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        int low = 0, high = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> v[j];
            if (j > 0 && v[j - 1] > v[j])
            {
                low++;
            }
            else
            {
                if (j > 0 && v[j - 1] < v[j])
                {
                    high++;
                }
            }
        }

        cout << "Case " << i + 1 << ": " << high << " " << low << endl;
    }
}