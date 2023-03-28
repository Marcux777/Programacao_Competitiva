#include <iostream>

using namespace std;

void inicia(string *M)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 9; i++)
        {
            if (i == 0)
            {
                M[i][j] = '1';
            }
            else
            {
                if (i == 1)
                {
                    M[i][j] = '0';
                }
                else
                {
                    if (i == 2)
                    {
                        M[i][j] = '-';
                    }
                    else
                    {
                        if (i == 3)
                        {
                            m[i][j] = '0';
                        }
                        else
                        {
                            m[i][j] = '1';
                        }
                    }
                }
            }
        }
    }
}

void Move(string *m, int n){
    int cont = 0;
    while(n > 10){
        for(int i = 0; i < n/10; i++){
            
        }
    }
}

int main()
{
    string m;
    int n;
    while(cin >> n){
        int aux;
        inicia(M);
        
        
    }
}