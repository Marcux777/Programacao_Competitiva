#include <bits/stdc++.h>

using namespace std;

#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)

signed main() {
    IOS;
    string s;
    while(getline(cin, s)) {
        string ans;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == 'C' && i > 0 && isalpha(s[i-1]) && !isalpha(s[i+1])){
                ans+="-se";
            }else ans+=s[i];
        }
        cout << ans << endl;
    }
}
