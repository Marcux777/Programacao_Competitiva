#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        cout << min(x, y) << " " << max(x, y) << endl;
    }
}