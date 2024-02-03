#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'
#define INF 1e9 + 7

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second > b.second;
    else
        return a.first < b.first;
}

int intersect(vector<pair<int, int>> &chords) {
    sort(chords.begin(), chords.end(), compare);
    stack<int> s;
    for (auto &chord : chords) {
        while (!s.empty() && chord.second > s.top()) {
            s.pop();
        }
        s.push(chord.second);
    }
    return chords.size() - s.size();
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for(auto &i : v) cin >> i.first >> i.second;

    cout << (intersect(v) != 0 ? "Yes" : "No") << endl;
    
}