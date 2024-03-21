#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define inf LLONG_MAX
#define Ninf LLONG_MIN
#define mod 1000000007

bool fodase(string s){
    if(s[0] != '<' || s[s.size()-1] != '>') return false;

    for(int i = 1; i < s.size()-1; i++){
        if(s[i] != '=') return false;
    }
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    cout << (fodase(s) ? "Yes" : "No") << endl;
    
}