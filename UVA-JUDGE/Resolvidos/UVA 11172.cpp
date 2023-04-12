#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("saida.txt", "w", stdout);
    int n;
    cin >> n;
    while(n--){
        int x, y;
        cin >> x >> y;
        if(x > y){
            cout << ">" << endl;
        }else{
            if(x < y){
                cout << "<" << endl;
            }else{
                cout << "=" << endl;
            }
        }
    }
    
}