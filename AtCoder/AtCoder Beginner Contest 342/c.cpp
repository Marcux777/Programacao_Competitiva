#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n;
    string s;
    cin >> s;

    vector<int> char_map(26);
    iota(char_map.begin(), char_map.end(), 0);

    cin >> q;
    while (q--) {
        char c, d;
        cin >> c >> d;
        for (int& m : char_map)
            if (m == c - 'a') m = d - 'a';
    }

    for (char& c : s)
        c = char_map[c - 'a'] + 'a';

    cout << s << endl;

    return 0;
}
