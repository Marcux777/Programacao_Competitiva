#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define vi vector<int>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i = n-1; i >= 0; i--){
        if(v[i] < v[n-1]){
            cout << v[i] << endl;
            return 0;
        }
    }
}