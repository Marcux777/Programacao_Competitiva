#include <bits/stdc++.h>

using namespace std;

struct a{
    string nome;
    int x, y, z;
};

bool comp(const a& aa, const a& bb){
    if(aa.x != bb.x) return aa.x > bb.x;
    else if(aa.y != bb.y) return aa.y > bb.y;
    else if(aa.z != bb.z) return aa.z < bb.z;
    else return aa.nome < bb.nome;
}

int main(){
    ios_base::sync_with_stdio(true);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<a> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].nome >> v[i].x >> v[i].y >> v[i].z;
    }

    sort(v.begin(), v.end(), comp);
    cout << v[0].nome << endl;
}