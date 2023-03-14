#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, ganhou = 0;
    bool ok;
    string s;

    cin >> n;
    while(n--){
        ok = false;
        cin >> s;
        for(int i = 0; i < s.size()-1; i++){
            if(s[i] == 'C'){
                if(s[i+1] == 'D'){
                    ok = true;
                }
            }
        }
        if(!ok){
            ganhou++;
        }
    }
    cout << ganhou << endl;
}