#include <iostream>
#include <string>

using namespace std;

bool isSubsequence(const string &s, const string &t)
{
    int i = 0, j = 0;
    int s_len = s.length();
    int t_len = t.length();
    
    while (i < s_len && j < t_len)
    {
        if (s[i] == t[j])
        {
            j++;
        }
        i++;
    }
    
    return j == t_len;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        int Q;
        cin >> Q;

        for (int j = 0; j < Q; j++)
        {
            string t;
            cin >> t;

            if (isSubsequence(s, t))
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }

    return 0;
}
