#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        int N, K, P;
        cin >> N >> K >> P;

        int pos = (K + P) % N;
        if (pos == 0)
        {
            pos = N;
        }

        cout << "Case " << i << ": " << pos << endl;
    }

    return 0;
}
