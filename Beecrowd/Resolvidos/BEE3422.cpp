#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, h;
    string s;
    cin >> t;
    while(t--){
        cin >> h >> s;
        if(s[0] == '1'){
            if(h > 45){
                cout << "45+" << (h-45) << endl;
            }else{
                cout << h << endl;
            }
        }else{//segundo tempo
            if((45+h) <= 90){
                cout << 45+h << endl;
            }else{
                cout << "90+" << ((45+h)-90) << endl;
            }
        }
    }
}