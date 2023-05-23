#include <iostream>

using namespace std;

int countZeros(int n)
{
    int zeros = 0;

    while (n >= 5)
    {
        zeros += n / 5;
        n /= 5;
    }

    return zeros;
}

int main()
{

    int n;
    cin >> n;

    int zeros = countZeros(n);

    cout << zeros << endl;

    return 0;
}
