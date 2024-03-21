#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s; cin >> s;
    int id = 0;
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] == s[i+1]){
            continue;
        }else{
            if(s[i-1] == s[i]){
                id = i+1;
            }else{
                id = i;
            }
        }
    }
    cout << id+1 << endl;
}