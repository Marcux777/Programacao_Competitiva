#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = n; i < 1000; i++){
        int a = i%10;
        int b = (i/10)%10;
        int c = ((i/10)/10)%10;
        if(b*c == a){
            n = i;
            break;
        }
    }
    cout << n << endl;

}