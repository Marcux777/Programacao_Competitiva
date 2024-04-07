#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    set<string> st;
    for (size_t i = 0; i < s.size(); ++i) {
        for (size_t j = i + 1; j <= s.size(); ++j) {
            st.insert(s.substr(i, j - i));
        }
    }

    cout << st.size() << endl;
    
}