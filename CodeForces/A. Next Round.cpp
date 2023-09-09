#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int c = v[k-1];
    int cont = 0;
    for(auto i : v){
        if(i > 0 && i >= c){
            cont++;
        }
    }
    cout << cont << endl;
}