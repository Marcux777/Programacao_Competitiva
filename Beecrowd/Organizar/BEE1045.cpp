// Tipos de Triângulos
#include <iostream>

using namespace std;

int main()
{
    float a, b, c, A, B, C;
    cin >> a >> b >> c;
    if (a >= b && a >= c)
    {
        A = a;
        if (b >= c)
        {
            B = b;
            C = c;
        }
        else
        {
            B = c;
            C = b;
        }
    }
    if (b >= a && b >= c)
    {
        A = b;
        if (a >= c)
        {
            B = a;
            C = c;
        }
        else
        {
            B = c;
            C = a;
        }
    }
    if (c >= b && c >= a)
    {
        A = c;
        if (a >= b)
        {
            B = a;
            C = b;
        }
        else
        {
            B = b;
            C = a;
        }
    }
    if (A >= B + C)
    {
        cout << "NAO FORMA TRIANGULO" << endl;
    }
    else
    {
        if (A * A == B * B + C * C)
        {
            cout << "TRIANGULO RETANGULO" << endl;
            return 0;
        }
        if (A * A > B * B + C * C)
        {
            cout << "TRIANGULO OBTUSANGULO" << endl;
            if (A == B && A == C)
            {
                cout << "TRIANGULO EQUILATERO" << endl;
            }
            if ((A == B && A != C) || (B == C && B != A) || (C == A && C != B))
            {
                cout << "TRIANGULO ISOSCELES" << endl;
            }
        }
        if (A * A < B * B + C * C)
        {
            cout << "TRIANGULO ACUTANGULO" << endl;
            if (A == B && A == C)
            {
                cout << "TRIANGULO EQUILATERO" << endl;
            }
            if ((A == B && A != C) || (B == C && B != A) || (C == A && C != B))
            {
                cout << "TRIANGULO ISOSCELES" << endl;
            }
        }
    }
}