#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n = 600851475143;
    while(n % 2 == 0)
        n /= 2;
    long long ans = 2;
    for(int i = 3; i <= sqrt(n); i++){
        while(n % i == 0){
            n /= i;
            ans = i;
        }
    }
    if(n > 2){
        ans = n;
    }
    cout << ans << endl;
}