#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

/*Oeste da pista têm maior prioridade de serem colocados na fila,
pois são aqueles que estão mais próximo do localizador (início da pista).
Já os aviões que estão se aproximando pelo lado Norte e Sul, devem ser inseridos na fila 1 por vez,
ou seja, insere-se 1 avião do lado Norte e em seguida 1 avião do lado Sul.
Por último, insere-se o próximo avião que esteja se aproximando ao lado leste da pista.

 (-4 representa o lado leste, -3 o lado norte, -2 lado sul e -1 lado oeste) */

int main()
{

    //freopen("saida.txt", "w", stdout);
    queue<string> oeste, norte, sul, leste;
    bool tem_norte = false, tem_sul = false, tem_oeste, tem_leste;
    string p;

    while (cin >> p && p != "0")
    {
        if (p == "-1")
        {
            tem_oeste = true;
            tem_leste = tem_norte = tem_sul = false;
        }
        else
        {
            if (p == "-2")
            {
                tem_sul = true;
                tem_oeste = tem_leste = tem_norte = false;
            }
            else
            {
                if (p == "-3")
                {
                    tem_norte = true;
                    tem_sul = tem_oeste = tem_leste = false;
                }
                else
                {
                    if (p == "-4")
                    {
                        tem_leste = true;
                        tem_sul = tem_oeste = tem_norte = false;
                    }
                    else
                    { // É um avião
                        if (tem_oeste && !tem_leste && !tem_norte && !tem_sul)
                        {
                            oeste.push(p);
                        }
                        else
                        {
                            if (!tem_oeste && tem_leste && !tem_norte && !tem_sul)
                            {
                                leste.push(p);
                            }
                            else
                            {
                                if (!tem_oeste && !tem_leste && tem_norte && !tem_sul)
                                {
                                    norte.push(p);
                                }
                                else
                                {
                                    if (!tem_oeste && !tem_leste && !tem_norte && tem_sul)
                                    {
                                        sul.push(p);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    while (!oeste.empty() || !leste.empty() || !sul.empty() || !norte.empty())
    {
        
        if (!oeste.empty())
        {
            cout << oeste.front();
            oeste.pop();
            if (oeste.size() == 0 && leste.size() == 0 && sul.size() == 0 && norte.size() == 0)
            {
                cout << endl;
            }
            else
            {
                cout << " ";
            }
        }
        if (!norte.empty())
        {
            cout << norte.front();
            norte.pop();
            if (oeste.size() == 0 && leste.size() == 0 && sul.size() == 0 && norte.size() == 0)
            {
                cout << endl;
            }
            else
            {
                cout << " ";
            }
        }
        if (!sul.empty())
        {
            cout << sul.front();
            sul.pop();
            if (oeste.size() == 0 && leste.size() == 0 && sul.size() == 0 && norte.size() == 0)
            {
                cout << endl;
            }
            else
            {
                cout << " ";
            }
        }
        if (!leste.empty())
        {
            cout << leste.front();
            leste.pop();
            if (oeste.size() == 0 && leste.size() == 0 && sul.size() == 0 && norte.size() == 0)
            {
                cout << endl;
            }
            else
            {
                cout << " ";
            }
        }
    }
}
