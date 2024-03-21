#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define inf LLONG_MAX
#define Ninf LLONG_MIN
#define mod 1000000007

vector<int> v;
int n, custo;

int f()
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < v.size(); i++)
    {
        max_ending_here = max_ending_here + v[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> n)
    {
        cin >> custo;
        v = vector<int>(n);
        for (auto &i : v){
            cin >> i;
            i -= custo;
        }
        int ans = f();
        cout << (ans <= 0 ? 0 : ans) << endl;
    }
}