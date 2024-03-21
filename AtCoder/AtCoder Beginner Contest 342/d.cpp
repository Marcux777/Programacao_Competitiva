#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define endl '\n'

int prime[200001] = {0};

int k[200001] = {0};

void Sieve()
{
    k[0] = 1;
    for (int i = 1; i < 200001; i++)
        k[i] = i;

    for (int i = 2; i < 200001; i++)
    {

        if (prime[i] == 0)
            for (int j = i; j < 200001; j += i)
            {

                prime[j] = 1;

                while (k[j] % (i * i) == 0)
                    k[j] /= (i * i);
            }
    }
}

int countPairs(int arr[], int n)
{
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        freq[k[arr[i]]]++;
    }

    int sum = 0;

    for (auto i : freq)
    {
        sum += ((i.second - 1) * i.second) / 2;
    }

    return sum;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, c;
    cin >> n;
    c = 0;
    int v[n];
    Sieve();
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] == 0)
        {
            c = n - 1;
        }
    }
    cout << countPairs(v, n) + c << endl;
}