#include <bits/stdc++.h>
using namespace std;

int cont = 0;

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {

        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int n, n1;
    cin >> n;
    while (n--)
    {
        cin >> n1;
        int v[n1], v2[n1];
        for (int i = 0; i < n1; i++)
        {
            cin >> v[i];
            v2[i] = v[i];
        }
        bubbleSort(v, n1);
        for (int i = 0; i < n1; i++)
        {
            if (v[i] == v2[i])
            {
                cont++;
            }
        }
        cout << cont << endl;
        cont = 0;
    }
}