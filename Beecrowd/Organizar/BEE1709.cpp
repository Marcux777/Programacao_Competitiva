#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int P;
    cin >> P;

    int firstCard = 1; // Primeira carta
    int Atual = firstCard;
    int TamCycle = 0;

    if (Atual <= P / 2)
    {
        Atual = Atual * 2;
    }
    else
    {
        Atual = (Atual - P / 2) * 2 - 1;
    }
    TamCycle++;

    while (Atual != firstCard)
    {
        if (Atual <= P / 2)
        {
            Atual = Atual * 2;
        }
        else
        {
            Atual = (Atual - P / 2) * 2 - 1;
        }
        TamCycle++;
    }

    cout << TamCycle << endl;

    return 0;
}
