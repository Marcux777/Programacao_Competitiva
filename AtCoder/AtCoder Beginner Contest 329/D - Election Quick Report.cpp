#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define vi vector<int>

int main(){
    int n, m;
    cin >> n >> m;
    vi cand(n+1);
    vi v(m);
    int maior = 0;
    int pos = 1;
    for(int i = 0; i < m; i++){
        cin >> v[i];
        cand[v[i]]++;
        if(cand[v[i]] >= maior){
            if(cand[v[i]] == maior) pos = min(pos, v[i]);
            else pos = v[i];
            maior = cand[v[i]];
            
        }
        cout << pos << endl;
    }
}