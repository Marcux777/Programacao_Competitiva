#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<pair<string, int>> circulo(n);
        for (int i = 0; i < n; i++) {
            cin >> circulo[i].first >> circulo[i].second;
        }

        int posi = 0;
        int v = circulo[posi].second;
        while (circulo.size() > 1) {
            posi = (posi + v) % circulo.size();
            v = circulo[posi].second;
            circulo.erase(circulo.begin() + posi);
            if(posi%2 != 0){
                posi--;
            }
            if(posi == circulo.size()){
                posi = 0;
            }
            
        }

        cout << "Vencedor(a): " << circulo[0].first << endl;
    }

    return 0;
}
