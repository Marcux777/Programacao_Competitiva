#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
    int n, qt, s; 
    cin >> n; 

    for (int i = 0; i < n; i++) 
    { 
        cin >> qt >> s; 

        int alunos[qt]; 
        int diferenca = INT_MAX; 
        int ganhador = 0; 

        for (int j = 0; j < qt; j++) 
        { 
            cin >> alunos[j]; 

            if (abs(s - alunos[j]) < diferenca) 
            { 
                diferenca = abs(s - alunos[j]); 
                ganhador = j + 1; 
            } 
        } 
        cout << ganhador << endl; 
    } 
    return 0; 
} 
