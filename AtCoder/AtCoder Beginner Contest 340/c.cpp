#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    int soma = 0;
    priority_queue<int> q;
    q.push(n);
    int x;
    while(!q.empty()){
        x = q.top();
        q.pop();
        soma += x;
        int a = x/2, b = x - a;
        if(a >= 2) q.push(a);
        if(b >= 2) q.push(b);
    }
    cout << soma << endl;
}