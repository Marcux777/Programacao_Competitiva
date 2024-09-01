#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int>v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        cout << lower_bound(v.begin(), v.end(), x) - v.begin() + 1<< endl; 
    }
}