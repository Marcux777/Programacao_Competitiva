#include <bits/stdc++.h>

using namespace std;

int main(){
    string nome;
    getline(cin, nome);

    for(int i = 0; nome[i] != ' '; i++){
        cout << nome[i];
    }
    cout << " san\n";
}