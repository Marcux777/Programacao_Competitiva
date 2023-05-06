#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Competidor
{
    int index;
    int reaction_time;
    int time_digit;
    int fase;
};

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("saida.txt", "w", stdout);
    int n;
    cin >> n;

    queue<Competidor> q;

    for (int i = 0; i < n; i++)
    {
        int r, e;
        cin >> r >> e;
        q.push({i + 1, r, e, 1});
    }

    string s;
    cin >> s;

    vector<int> fases(n);

    int len_s = s.length();
    while (q.size() > 1)
    {

        Competidor c1 = q.front();
        q.pop();
        Competidor c2 = q.front();
        q.pop();

        if (c1.fase != c2.fase)
        {
            c1.fase = max(c1.fase, c2.fase);
            c2.fase = max(c1.fase, c2.fase);
        }

        int time_c1 = c1.reaction_time + c1.time_digit * len_s * (1 << (c1.fase - 1));
        int time_c2 = c2.reaction_time + c2.time_digit * len_s * (1 << (c2.fase - 1));

        if (time_c1 < time_c2)
        {
            c1.fase++;
            q.push(c1);
        }
        else
        {
            if (time_c2 < time_c1)
            {
                c2.fase++;
                q.push(c2);
            }
            else
            {
                if (c1.index < c2.index)
                {
                    c1.fase++;
                    q.push(c1);
                }
                else
                {
                    c2.fase++;
                    q.push(c2);
                }
            }
        }

        fases[c1.index - 1] = c1.fase;
        fases[c2.index - 1] = c2.fase;
    }

    fases[q.front().index - 1] = q.front().fase;

    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            cout << fases[i];
        }
        else
        {
            cout << fases[i] << " ";
        }
    }
    cout << endl;

    return 0;
}