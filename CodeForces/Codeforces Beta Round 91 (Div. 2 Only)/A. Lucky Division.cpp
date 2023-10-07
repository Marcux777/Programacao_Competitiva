#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bool lucky = false;
    long long int n;
    cin >> n;
    lucky = (n%4==0 || n%7==0 || n%44==0|| n%47==0 || n%74==0 ||n%77==0 || n%444==0 || n%447==0 || n%474==0 || n%744==0 || n%477==0 || n%747==0 || n%774==0 || n%777==0);
    if(lucky){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}