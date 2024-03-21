#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define inf LLONG_MAX
#define Ninf LLONG_MIN
#define mod 1000000007

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, resp;
    bool barrinha = false;
    cin >> s;
    for (auto i : s)
    {
        if (i == '|')
        {
            barrinha = !barrinha;
            continue;
        }
        if (!barrinha)
        {

            resp += i;
        }
    }
    cout << resp << endl;
}