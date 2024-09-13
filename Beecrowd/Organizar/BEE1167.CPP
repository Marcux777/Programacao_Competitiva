#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct AlunoNode
{
    string name;
    int value;
    int prev, next;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    while (cin >> N && N)
    {

        vector<AlunoNode> Circulo(N);

        for (int i = 0; i < N; ++i)
        {
            cin >> Circulo[i].name >> Circulo[i].value;
            Circulo[i].prev = ((i - 1) % N + N) % N;
            Circulo[i].next = (i + 1) % N;
        }

        int i = 0;
        while (N > 1)
        {
            int value = Circulo[i].value;

            if (value % 2)
            {
                for (int j = 0; j < value; ++j)
                {
                    i = Circulo[i].next;
                }
            }
            else
            {
                for (int j = 0; j < value; ++j)
                {
                    i = Circulo[i].prev;
                }
            }

            Circulo[Circulo[i].prev].next = Circulo[i].next;
            Circulo[Circulo[i].next].prev = Circulo[i].prev;

            --N;
        }

        i = Circulo[i].next;
        cout << "Vencedor(a): " << Circulo[i].name << std::endl;
    }

    return 0;
}
