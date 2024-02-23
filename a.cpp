#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>

using namespace std;

int main()
{
    int d1, h1, m1, s1, d2, h2, m2, s2, x, y, z, hh, mm, ss;
    char di1[10], a, b, di2[10], c, d;
    cin >> di1 >> d1;
    //scanf("%d", &d1);
    scanf("%d%s%d%s%d", &h1, &a, &m1, &b, &s1);
    cin >> di2;
    scanf("%d", &d2);
    scanf("%d%s%d%s%d", &h2, &c, &m2, &d, &s2);
    //printf("%d %d\n", d1, d2);
    x = d1*86400+h1*3600+m1*60+s1;
    y = d2*86400+h2*3600+m2*60+s2;
    if (h1 == h2 && m1 == m2 && s1 == s2)
    {
        d1 = d2-d1+1;
        printf("%d dia(s)\n0 hora(s)\n0 minuto(s)\n0 segundo(s)\n", d1);
    }
    else
    {
        d1 = (y-x)/86400;
        z = (y-x)%86400;
        hh = z/3600;
        mm = z/60%60;
        ss = z%60;
        printf("%d dia(s)\n%d hora(s)\n%d minuto(s)\n%d segundo(s)", d1, hh, mm, ss);
    }
}