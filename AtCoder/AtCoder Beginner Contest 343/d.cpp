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
    int n, t;
    cin >> n >> t;
    vector<int> a, b;
    vector<int> score(n);
    a.resize(t);
    b.resize(t);
    for (int i = 0; i < t; i++)
    {
        cin >> a[i] >> b[i];
        a[i]--;
    }
    map<int, int> freq;
    freq[0] = n;

    for(int i = 0; i < t; i++) {
        freq[score[a[i]]]--;
        if(freq[score[a[i]]] == 0) {
            freq.erase(score[a[i]]);
        }
        score[a[i]] += b[i];
        freq[score[a[i]]]++;
        cout << freq.size() << endl;
    }
}