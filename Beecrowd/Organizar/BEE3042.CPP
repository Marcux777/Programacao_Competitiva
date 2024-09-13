#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n)
    {
        int toque = 0;
        int m[n][3];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> m[i][j];
            }
        }
        int j = 1;

        for (int i = 0; i < n; i++)
        {
            if (i == 0 && j == 1 && m[i][j] == 1)
            {
                if (m[i][j - 1] == 0)
                {
                    j--;
                    toque++;
                }
                else
                {
                    if (m[i][j + 1] == 0)
                    {
                        j++;
                        toque++;
                    }
                }
            }
            if (i > 0 && m[i][j] == 1)
            {
                if (j == 0)
                {
                    if (m[i][j + 1] == 0)
                    {
                        j++;
                        toque++;
                    }
                    else
                    {
                        if (m[i][j + 2] == 0)
                        {
                            j += 2;
                            toque += 2;
                        }
                    }
                }
                else
                {
                    if (j == 1)
                    {
                        if (m[i][j - 1] == 0)
                        {
                            j--;
                            toque++;
                        }
                        else
                        {
                            if (m[i][j + 1] == 0)
                            {
                                j++;
                                toque++;
                            }
                        }
                    }
                    else
                    {
                        // j == 2
                        if (m[i][j - 1] == 0)
                        {
                            j--;
                            toque++;
                        }
                        else
                        {
                            if (m[i][j - 2] == 0)
                            {
                                j -= 2;
                                toque += 2;
                            }
                        }
                    }
                }
            }
        }
        cout << toque << endl;
        cin >> n;
    }
}
