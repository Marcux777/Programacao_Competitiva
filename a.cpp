#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, y = 0;
    cin >> N;
    deque<string> painel;
    painel.push_back("FACE");
    string letras, invertidas;
    char letra;

    for(int i = 0; i < N; i++) {
        letras.clear();
        for(int x = 0; x < 4; x++) {
            cin >> letra;
            letras.push_back(letra);
        }

        invertidas = letras;
        reverse(invertidas.begin(), invertidas.end());

        if (painel.back() == invertidas) {
            y++;
            cout <<y <<endl;
            painel.pop_back();
        } else {
            painel.push_back(letras);
        }

        if (painel.empty()) {
            painel.push_back("FACE");
        }
    }

    cout << y << endl;
}