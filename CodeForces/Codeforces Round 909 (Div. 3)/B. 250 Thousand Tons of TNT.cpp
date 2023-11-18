#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define endl '\n'
#define f first
#define s second
#define all(x) (x).begin(), (x).end() //obter um intervalo que abrange todo o contêiner
#define fi(x) find()
#define sz(x) ((int)(x).size()) // tamanho
#define pb push_back
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define vll vector<long long>
#define PI 3.14159265358979323846

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vll v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }   
        sort(all(v));
        long long sum = 0, resp = 0;
        for(auto i : v){
            sum += i;
        }
        resp = sum - 2*v[0];
        for(int i = 1; i < n; i++){
            sum -= v[i];
            resp = max(resp, sum - 2*v[i]);
        }
        cout << resp << endl;
    }
}