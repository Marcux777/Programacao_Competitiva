#include <bits/stdc++.h>

using namespace std;

int main()
{
     ios::sync_with_stdio(false);
     cin.tie(0);
    // cout.tie(0);
    int x, y;
    cin >> x >> y;
    if(x < y){
        if(abs(x - y) >= 3){ 
            cout << "No\n";
        }else{
            cout << "Yes\n";
        }
    }else{
        if(abs(x - y) > 3){
            cout << "No\n";
        }else{
            cout << "Yes\n";
        }
    }
}