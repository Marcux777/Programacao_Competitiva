#include <iostream>
#include <string.h>
using namespace std;

void convert_dec_to_hex(int x)
{
    long long int r, aux;
    int i = 0;
    char hex[20];
    memset(hex, 0, 20);
    while (x > 0)
    {
        r = x % 16;
        x /= 16;
        if (r < 10)
        {
            hex[i] = r + 48;
        }
        else if (r == 10)
        {
            hex[i] = 'A';
        }
        else if (r == 11)
        {
            hex[i] = 'B';
        }
        else if (r == 12)
        {
            hex[i] = 'C';
        }
        else if (r == 13)
        {
            hex[i] = 'D';
        }
        else if (r == 14)
        {
            hex[i] = 'E';
        }
        else if (r == 15)
        {
            hex[i] = 'F';
        }
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        cout << hex[j];
    }
}
int main()
{
    int n;
    cin >> n;
    convert_dec_to_hex(n);
    cout << endl;
}