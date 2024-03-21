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
    string s;
    stack<string> st;
    while(getline(cin, s) && !s.empty()) {
        st.push(s);
    }
    while(!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
}