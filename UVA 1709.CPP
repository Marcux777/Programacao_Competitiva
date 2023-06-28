#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    int p, a, b, c, d, n;
    cin >> p >> a >> b >> c >> d >> n;
    vector<double>vet(n);
    double check, MaiorDif = 0.0;
    for(int i = 0; i < n; i++){
        vet[i] = p * (sin(double(a*(i+1) + b))) + (cos(double(c*(i+1) + d + 2)));
    }
    sort(vet.begin(), vet.end());
    MaiorDif = abs(vet[0] - vet[vet.size() - 1]);
    cout << MaiorDif << endl;
}