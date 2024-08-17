#include <bits/stdc++.h>

using namespace std;

#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)
#define pb push_back
#define all(v) v.begin(), v.end()
#define f first
#define s second
#define Unique(v) \
    sort(all(v)); \
    v.erase(unique(all(v)), v.end());
#define sz(v) ((int)v.size())
#define sor(x) sort(all(x))
#define ft front()
#define bk back()
#define endl "\n"
#define rep(i, a, b) for (int i = a; i < (b); ++i)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<pii> vii;
typedef vector<piii> viii;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int mod = 1e9 + 7;
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << _VA_ARGS_ << "):", dbg_out(_VA_ARGS_), cerr << endl

vector<int> buildSuffixArray(const string& s) {
    int n = s.size();
    vector<int> sa(n), rank(n);

    for (int i = 0; i < n; ++i) {
        sa[i] = i;
        rank[i] = s[i];
    }

    for (int k = 1; k < n; k <<= 1) {
        // Sort based on pairs (rank[i], rank[i + k])
        sort(sa.begin(), sa.end(), [&](int i, int j) {
            if (rank[i] != rank[j]) return rank[i] < rank[j];
            return (i + k < n ? rank[i + k] : -1) < (j + k < n ? rank[j + k] : -1);
        });

        // Update rank array based on the sorted order
        vector<int> newRank(n);
        newRank[sa[0]] = 0;
        for (int i = 1; i < n; ++i) {
            newRank[sa[i]] = newRank[sa[i - 1]];
            if ((rank[sa[i]] != rank[sa[i - 1]]) ||
                (sa[i] + k >= n && sa[i - 1] + k < n) ||
                (sa[i] + k < n && sa[i - 1] + k >= n) ||
                (sa[i] + k < n && sa[i - 1] + k < n && rank[sa[i] + k] != rank[sa[i - 1] + k])) {
                newRank[sa[i]]++;
            }
        }
        rank = newRank;

        if (rank[sa[n - 1]] == n - 1) break; // Optimization: Stop if ranks are unique
    }
    return sa;
}

vector<int> buildLCPArray(const string& s, const vector<int>& sa) {
    int n = s.size();
    vector<int> lcp(n, 0);
    vector<int> invSa(n); // Inverse suffix array: invSa[sa[i]] = i

    for (int i = 0; i < n; ++i) {
        invSa[sa[i]] = i;
    }

    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (invSa[i] == n - 1) { // Last suffix has no next suffix
            k = 0;
            continue;
        }

        int j = sa[invSa[i] + 1]; // Next suffix in lexicographical order
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
            k++;
        }
        lcp[invSa[i]] = k;
        if (k > 0) k--; // LCP property: lcp[i] >= lcp[i-1] - 1
    }
    return lcp;
}

bool substringExists(const string& s, const vector<int>& sa, const string& sub) {
    int n = s.size(), m = sub.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = strncmp(s.c_str() + sa[mid], sub.c_str(), m);
        if (cmp == 0) {
            return true;
        } else if (cmp < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

int countSubstringOccurrences(const string& s, const vector<int>& sa, const vector<int>& lcp, const string& sub) {
    int n = s.size(), m = sub.size();
    int low = 0, high = n - 1;
    int firstOccurrence = -1, lastOccurrence = -1;

    // Find the first occurrence
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = strncmp(s.c_str() + sa[mid], sub.c_str(), m);
        if (cmp == 0) {
            firstOccurrence = mid;
            high = mid - 1; // Continue searching left for potentially earlier occurrences
        } else if (cmp < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // If no occurrence is found, return 0
    if (firstOccurrence == -1) {
        return 0;
    }

    // Reset search range to find the last occurrence
    low = 0, high = n - 1;

    // Find the last occurrence
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = strncmp(s.c_str() + sa[mid], sub.c_str(), m);
        if (cmp == 0) {
            lastOccurrence = mid;
            low = mid + 1; // Continue searching right for potentially later occurrences
        } else if (cmp < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Use LCP array to efficiently count occurrences between first and last
    int count = lastOccurrence - firstOccurrence + 1;
    for (int i = firstOccurrence; i < lastOccurrence; ++i) {
        count -= (lcp[i] >= m); // Subtract if LCP is greater than or equal to substring length
    }

    return count;
}

void solve() {
    string s; cin >> s;
    vector<int> sa = buildSuffixArray(s);
    vector<int> lcp = buildLCPArray(s, sa);

    int t; cin >> t;
    while (t--) {
        string sub; cin >> sub;
        cout << countSubstringOccurrences(s, sa, lcp, sub) << endl;
    }
}

int32_t main()
{
    IOS;
    int tt;
    tt = 1;
    while (tt--)
        solve();
    return 0;
}