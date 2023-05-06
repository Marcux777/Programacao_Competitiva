#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("saida.txt", "w", stdout);
    int P, Q;
    cin >> P >> Q;
    vector<tuple<int, int, string>> avistamentos;
    for (int i = 0; i < Q; i++) {
        string H, N;
        cin >> H >> N;
        int hora = stoi(H.substr(0, 2));
        int minuto = stoi(H.substr(3, 2));
        if (hora == 23) {
            minuto = minuto - 60;
        }
        if (abs(minuto) <= P) {
            avistamentos.push_back(make_tuple(minuto, i, N));
        }
    }
    sort(avistamentos.begin(), avistamentos.end());
    for (auto avistamento : avistamentos) {
        cout << get<2>(avistamento) << endl;
    }
    return 0;
}