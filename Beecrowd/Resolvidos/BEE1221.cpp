#include <iostream>
using namespace std;
int main()
{
    int n, cont;
    long int num;
    scanf("%d", &n);
    while (n--)
    {
        cont = 0;
        scanf("%d", &num);
        for (int j = 2; j < num; j++)
        {
            if (num % j == 0)
            {
                cont++;
                printf("Not Prime\n");
                break;
            }
        }
        if (cont == 0)
        {
            printf("Prime\n");
        }
    }
}