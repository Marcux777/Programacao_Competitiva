#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, aux, split;
    getline(cin, s);
    //cin.ignore();
    while(s[0] != '*'){
        aux[0] = s[0];
        bool ok = true;
        for(int i = 0; ok && i < s.size(); i++){
            if(i > 0){
                if(s[i-1] == ' '){
                    if(s[i] == s[0] || abs(s[i] - s[0]) == 32){
                        ok = true;
                    }else{
                        ok = false;
                    }
                }
            }
        }
        if(ok){
            cout << "Y" << endl;
        }else{
            cout << "N" << endl;
        }
        getline(cin, s);
    }
}