#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(auto &i : a) cin >> i;

        int ans = 0;

        for(int i = 1; i < n; i++){
            if(a[i] < a[i-1]){
                int dif = a[i-1] - a[i];
                int b = 0;
                while(dif > 0){
                    b++;
                    dif >>= 1;
                }
                ans = max(ans, b);
                a[i] = a[i-1];
            }

        }
        cout << ans << endl;
    }
}