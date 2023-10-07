#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int min = 10000000;
    for(int i = 0; i < n; i++){
        if(abs(v[i]) <= min){
            min = abs(v[i]);
        }
    }
    cout << min << endl;
}