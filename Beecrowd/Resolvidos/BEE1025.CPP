#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp vays */
    int L[n1], R[n2];

    /* Copy data to temp vays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = v[l + i];
    for (j = 0; j < n2; j++)
        R[j] = v[m + 1 + j];

    /* Merge the temp vays back into v[l..r]*/
    i = 0; // Initial index of first subvay
    j = 0; // Initial index of second subvay
    k = l; // Initial index of merged subvay
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1)
    {
        v[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2)
    {
        v[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-vay of v to be sorted */
void mergeSort(vector<int> &v, int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);

        merge(v, l, m, r);
    }
}

int binarySearch(vector<int> &v, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (v[mid] == x)
        {
            return mid;
        }

        // If element is smaller than mid, then
        // it can only be present in left subvay
        if (v[mid] > x)
            return binarySearch(v, l, mid - 1, x);

        // Else the element can only be present
        // in right subvay
        return binarySearch(v, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in vay
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q, n1, sla, cont = 1;
    cin >> n >> q;

    while (n || q)
    {
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> n1;
            v.push_back(n1);
        }
        int s = v.size();
        mergeSort(v, 0, s - 1);
        cout << "CASE# " << cont++ << ":" << endl;
        for (int i = 0; i < q; i++)
        {
            cin >> sla;

            int aux = binarySearch(v, 0, s - 1, sla);
            if (aux >= 0)
            {
                if (v[aux - 1] == v[aux])
                {
                    while (v[aux - 1] == v[aux])
                    {
                        aux--;
                    }
                }
                cout << sla << " found at " << aux + 1 << endl;
            }
            else
            {
                cout << sla << " not found" << endl;
            }
        }
        cin >> n >> q;
    }
}