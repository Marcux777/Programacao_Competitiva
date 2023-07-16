#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    if (a > b || a == b)
    {

        if (b >= 97)
            printf("cheia\n");
        else if (b <= 96 && b >= 3)
            printf("minguante\n");
        else
            printf("nova\n");
    }
    else
    {

        if (b <= 2)
            printf("nova\n");
        else if (b <= 96)
            printf("crescente\n");
        else if (b <= 100)
            printf("cheia\n");
    }
}
