#include <iostream>
#include <queue>

using namespace std;

struct Processo {
    int t, c;
};

bool operator<(const Processo& p1, const Processo& p2) {
    return p1.t > p2.t;
}

int main() {
    int n;
    while (cin >> n) {
        priority_queue<Processo> fila;
        for (int i = 0; i < n; i++) {
            int t, c;
            cin >> t >> c;
            fila.push({t, c});
        }
        int tempo = 0, espera = 0;
        while (!fila.empty()) {
            Processo p = fila.top();
            fila.pop();
            tempo = max(tempo, p.t);
            espera += tempo - p.t;
            tempo += p.c;
        }
        cout << espera << endl;
    }
    return 0;
}
