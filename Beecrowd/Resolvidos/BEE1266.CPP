#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while (cin >> n && n != 0) {
        vector<int> fence(n);
        int wood_post = 0;

        for (int i = 0; i < n; i++) {
            cin >> fence[i];
        }

        for (int i = 0; i < n; i++) {
            if (fence[i] == 0 && fence[(i+1)%n] == 0 && fence[(i+2)%n] == 0) {
                fence[(i+1)%n] = 1;
                wood_post++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (fence[i] == 0 && fence[(i+1)%n] == 0) {
                fence[(i+1)%n] = 1;
                wood_post++;
            }
        }

        cout << wood_post << "\n";
    }
    
    return 0;
}
