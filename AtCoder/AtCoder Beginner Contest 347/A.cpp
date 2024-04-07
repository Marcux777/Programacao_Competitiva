#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    queue<int>v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x%k == 0){
            v.push(x/k);
        }
    }
    while(v.size()){
        cout << v.front() << " ";
        v.pop();
    }
    
}