#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int>presente(n);
    for(auto i = 0; i < n; i++) {
        cin >> presente[i];
    }
    sort(presente.begin(), presente.end());
    int maxPresente = 0;
    int l = 0, r= 0;
    while(r < n){
        if(presente[r] - presente[l] < m)
            r++;
        else
            l++;
        maxPresente = max(maxPresente, r-l);
    }
    cout << maxPresente << endl;
}