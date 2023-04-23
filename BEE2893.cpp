#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000007;

// Função para computar o N-ésimo termo da sequência de Fibonacki
int fibonacki(int k, int N) {
    vector<unsigned long long int> f(k, 0);
    f[0] = 0;
    f[1] = 1;

    unsigned long long int sum = 1;
    for (int i = 2; i <= N; i++) {
        int index = i % k;
        f[index] = sum;
        sum = (sum - f[(i - k) % k] + f[index] + MOD) % MOD;
    }

    return f[N % k];
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int k, N;
        cin >> k >> N;

        int result = fibonacki(k, N);
        cout << result << endl;
    }

    return 0;
}
