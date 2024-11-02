#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>

using namespace std;

struct Array{
    vector<pair<int, int> > dims; // Dimensões (L, U), índices de 1 a D
    vector<long> C;               // Constantes C0 a CD, índices de 0 a D
    long b, C0;                   // Endereço base e constante C0
    int d;                        // Número de dimensões
    long element_size;            // Tamanho do elemento em bytes
};

int main(){
    int n, m; 
    cin >> n >> m;
    map<string, Array> arrays;
    while(n--){
        string name;
        cin >> name;
        Array arr;
        cin >> arr.b >> arr.element_size >> arr.d;
        arr.dims.resize(arr.d + 1); // Índices de 1 a arr.d
        for(int i = 1; i <= arr.d; i++){
            cin >> arr.dims[i].first >> arr.dims[i].second;
        }
        arr.C.resize(arr.d + 1); // Índices de 0 a arr.d
        arr.C[arr.d] = arr.element_size; // CD = tamanho do elemento
        for(int i = arr.d - 1; i >= 1; i--){
            arr.C[i] = arr.C[i + 1] * (arr.dims[i + 1].second - arr.dims[i + 1].first + 1);
        }
        arr.C[0] = arr.b;
        for(int i = 1; i <= arr.d; i++){
            arr.C[0] -= arr.C[i] * arr.dims[i].first;
        }
        arrays[name] = arr;
    }
    while(m--){
        string name;
        cin >> name;
        Array arr = arrays[name];
        vector<int> indexes(arr.d + 1);
        for(int i = 1; i <= arr.d; i++)
            cin >> indexes[i];
        long ans = arr.C[0];
        for(int i = 1; i <= arr.d; i++)
            ans += arr.C[i] * indexes[i];
        cout << name << "[";
        for(int i = 1; i <= arr.d; i++){
            if(i > 1) cout << ", ";
            cout << indexes[i];
        }
        cout << "] = " << ans << endl;
    }
    return 0;
}