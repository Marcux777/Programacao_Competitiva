#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string t;
    cin >> t;
    bool a = true;
    for(int i = 0; i < t.size() - 1 && a; i++){
        if(t[i] <= t[i+1]){
            a = false;
        }
    }
    if(a){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
}
