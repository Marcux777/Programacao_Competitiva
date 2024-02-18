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
        vector<int> v(n+1);
        for(int i = 1; i <= n; i++) cin >> v[i];

        int ano = 0;
        for(int i = 1; i <= n; i++){
            if(v[i] <= ano){
                int j = 2;
                while(v[i]*j <= ano) j++;

                ano = v[i]*j;
            }else{
                ano = v[i];
            }
        }
        cout << ano << endl;
    }

}