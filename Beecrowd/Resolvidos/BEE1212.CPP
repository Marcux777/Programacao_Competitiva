#include <iostream>
using namespace std;
int main()
{
    int num1, num2, soma, vai1;
    int n1;
    int n2;
    cin >> num1 >> num2;
    while (num1 != 0 || num2 != 0)
    {
        vai1 = 0;
        soma = 0;
        while (num1 > 0 || num2 > 0)
        {
            n1 = num1 % 10;
            num1 /= 10;
            n2 = num2 % 10;
            num2 /= 10;

            soma += n1 + n2;
            if (soma > 9)
            {
                vai1++;
                soma = 1;
            }
            else
            {
                soma = 0;
            }
        }
        if (vai1 == 0)
        {
            cout << "No carry operation." << endl;
        }
        else if (vai1 == 1)
        {
            cout << vai1 << " carry operation." << endl;
        }
        else
        {
            cout << vai1 << " carry operations." << endl;
        }
        cin >> num1 >> num2;
    }
}