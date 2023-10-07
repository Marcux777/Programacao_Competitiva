#include <iostream>
#include <math.h>

using namespace std;

int main(){
    long long int n, m, a;
    cin >> n >> m >> a;
    long double b = (ceil((long double)n/a)) * (ceil((long double)m/a));
    cout << (long long int)b << endl;
}