#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream cin("censor.in");
    ofstream cout("censor.out");
    string s, t;
    cin >> s >> t;
    stack<char> st;
    for (auto i : s)
    {
        st.push(i);

        if (st.top() == t.back())
        {
            string a;
            int tam = t.size();
            while (tam-- && st.size())
            {
                a += st.top();
                st.pop();
            }
            reverse(a.begin(), a.end());
            if (a == t)
                continue;
            else
                for (auto j : a)
                    st.push(j);
        }
    }
    string a;
    while (st.size())
    {
        a += st.top();
        st.pop();
    }
    reverse(a.begin(), a.end());
    cout << a << endl;
}