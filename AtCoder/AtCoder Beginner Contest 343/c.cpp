#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define inf LLONG_MAX
#define Ninf LLONG_MIN
#define mod 1000000007

bool isPalindrome(int n)
{
    string str = to_string(n);
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
    return str == revStr;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    int maxi = 1;

    for (int i = 1; i*i*i <= n; i++)
    {
        int x = i*i*i;
        if(isPalindrome(x)){
            maxi = x;
        }
    }
    cout << maxi << endl;

}