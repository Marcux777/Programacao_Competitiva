#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct telephone
{
    string phone;
};

bool compare(const telephone &a, const telephone &b)
{
    return a.phone < b.phone;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n)
    {
        int total = 0;
        vector<telephone> listPhone(n);

        for (int i = 0; i < n; i++)
        {
            cin >> listPhone[i].phone;
        }

        sort(listPhone.begin(), listPhone.end(), compare);

        int nCharacters = listPhone[0].phone.size();
        int i = 0, next = 0, savedCharacters = 0;
        while (++next != n)
        {
            for (int j = 0; j < nCharacters; j++)
            {
                if (listPhone[i].phone[j] == listPhone[next].phone[j])
                {
                    ++savedCharacters;
                }
                else
                {
                    i = next;
                    break;
                }
            }
        }
        cout << savedCharacters << endl;
    }

    return 0;
}
