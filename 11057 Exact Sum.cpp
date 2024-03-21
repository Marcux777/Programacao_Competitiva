#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define inf LLONG_MAX
#define Ninf LLONG_MIN
#define mod 1000000007

pair<int, int> f(vector<int>&v, int valor){
    int l = 0, r = v.size()-1;
    while(l < r && v[l] + v[r] != valor){
        int mid = l + (r-l)/2;
        if(v[l] + v[r] < valor){
            l = mid + 1;
        }else{
            if(v[l] + v[r] > valor){
                r = mid;
            }
        }
    }
    cout << l << " " << r << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, valor;
    while (cin >> n)
    {
        vector<int> v(n);
        for(auto &i : v) cin >> i;
        cin >> valor;
        sort(v.begin(), v.end());
        pair<int, int> a = f(v, valor);
        for(auto i : v) cout << i << " ";
        cout<<"Peter should buy books whose prices are " << v[a.first] << " and "<< v[a.second] <<"."<< endl;
        cout << endl;

    }
}