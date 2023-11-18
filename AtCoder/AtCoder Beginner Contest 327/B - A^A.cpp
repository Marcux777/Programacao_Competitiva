#include <cmath>
#include <iostream>

using namespace std;

double binarySearch(long double B) {
    long double low = 0, high = B;
    while (high - low > 1e-18) {
        long double mid = (low + high) / 2;
        if (pow(mid, mid) > B)
            high = mid;
        else
            low = mid;
    }
    return low;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long double b;
    cin >> b;
    long double a =  ceil(binarySearch(b));
    if(fabs(pow(a, a) - b) <= 1e-6){
        cout << a << endl;
    }else{
        cout << -1 << endl;
    }
}
