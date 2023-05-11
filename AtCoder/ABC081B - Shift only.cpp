#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    bool IsPar = true;
    int cont = 0;
    while (IsPar)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] % 2 == 0)
            {
                v[i] /= 2;
            }
            else
            {
                IsPar = false;
            }
        }
        if (IsPar)
        {
            cont++;
        }
    }
    cout << cont << endl;
}