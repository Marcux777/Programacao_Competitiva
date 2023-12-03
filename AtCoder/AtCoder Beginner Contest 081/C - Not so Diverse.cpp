#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1e9
#define endl '\n'
#define f first
#define s second
#define all(x) (x).rbegin(), (x).rend() //obter um intervalo que abrange todo o contêiner
#define fi(x) find()
#define sz(x) ((int)(x).size()) // tamanho
#define pb push_back
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define vll vector<long long>
#define PI 3.14159265358979323846

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;

    vi A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vi freq(2e5, 0);
    for (int i = 0; i < n; i++) {
        freq[A[i]]++;
    }

    sort(all(freq));

    int result = 0;
    for (int i = k; i < 2e5; i++) {
        result += freq[i];
    }

    cout << result << endl;

    return 0;
}
