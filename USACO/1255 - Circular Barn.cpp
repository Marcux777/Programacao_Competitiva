#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_A = 5000000;
vector<int> grundy(MAX_A + 1, 0);
vector<bool> is_prime(MAX_A + 1, true);

// Função para calcular números primos usando Crivo de Eratóstenes
void calculate_primes() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX_A; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_A; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

// Calcula os Grundy numbers
void calculate_grundy() {
    for (int i = 1; i <= MAX_A; ++i) {
        set<int> reachable;
        reachable.insert(grundy[i - 1]); // Jogada de remover 1 vaca

        // Remover números primos de vacas
        for (int j = 2; j <= i; ++j) {
            if (is_prime[j] && i >= j) {
                reachable.insert(grundy[i - j]);
            }
        }

        // Calcula o mínimo excluinte (mex) do conjunto
        int mex = 0;
        while (reachable.count(mex)) {
            ++mex;
        }
        grundy[i] = mex;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    calculate_primes();
    calculate_grundy();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int xor_sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            xor_sum ^= grundy[a[i]];
        }

        if (xor_sum == 0) {
            cout << "Farmer Nhoj\n";
        } else {
            cout << "Farmer John\n";
        }
    }

    return 0;
}
