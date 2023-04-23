#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n && n != 0)
    {
        stack<int> S;
        long long int max_area = 0, area;
        int i = 0;
        int h[n];

        while (i < n)
        {
            cin >> h[i];

            while (!S.empty() && h[i] < h[S.top()])
            {
                int tp = S.top();
                S.pop();

                /*A altura do retângulo é a altura do topo da pilha (h[tp]).
                A largura do retângulo é dada pela diferença entre a posição atual
                e a posição do topo da pilha (i - S.top() - 1).*/
                area = (long long int)h[tp] * (S.empty() ? i : i - S.top() - 1);
                if (area > max_area)
                {
                    max_area = area;
                }
            }

            S.push(i);
            i++;
        }

        while (!S.empty())
        {
            int tp = S.top();
            S.pop();

            area = (long long int)h[tp] * (S.empty() ? i : i - S.top() - 1);
            if (area > max_area)
            {
                max_area = area;
            }
        }

        cout << max_area << endl;
    }
    return 0;
}
