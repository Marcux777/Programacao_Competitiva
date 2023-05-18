#include <bits/stdc++.h>


using namespace std;

long long findDigits(int n)
{
    // factorial of -ve number
    // doesn't exists
    if (n < 0)
        return 0;

    // base case
    if (n <= 1)
        return 1;

    // Use Kamenetsky formula to calculate
    // the number of digits
    double x = ((n * log10(n / M_E) +
                 log10(2 * M_PI * n) /
                     2.0));

    return floor(x) + 1;
}

int main()
{
    int N;
    cin >> N;

    long long int numDigits = findDigits(N);
    cout << numDigits << endl;

    return 0;
}
