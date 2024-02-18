#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s;
        cin >> s;
        int maxM = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '@'){
                maxM++;
                continue;
            }
            if(s[i] == '*'){
                if(i == n-1 || (i < n-1 && s[i+1] == '*')){
                    break;
                }else{
                    continue;
                }
            }
        }
        cout << maxM << endl;
    }


}