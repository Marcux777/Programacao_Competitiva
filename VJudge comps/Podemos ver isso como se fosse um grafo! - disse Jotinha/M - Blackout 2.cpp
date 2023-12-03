#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k = 0;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= i; j++)
            for (int l = 1; l <= j; l++)
                k++;

    cout << k << endl;
}