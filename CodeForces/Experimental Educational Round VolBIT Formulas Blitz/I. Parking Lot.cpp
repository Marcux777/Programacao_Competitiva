#include <iostream>

using namespace std;

long long binpower(long long a, long long b){
    long long res = 1;
    if (b == 0)
        return res;
    while(b>0){
        if(b&1) res=res*a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
 
long long solve(long long n){
    return (2 * 3 *4 * binpower(4, n - 3) + 4*3*3*(n-3)*binpower(4, n - 4));
}
 
int main(){
    long long n;
    cin>>n;
    cout << solve(n)<<endl;
    return 0;
}