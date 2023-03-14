#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, fim;
    string str;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        if(str[0] == str[2]){
            fim = (str[0] - '0') * (str[2] - '0');
        }else{
            if(str[1] >= 'A' && str[1] <= 'Z'){
                fim = (str[2] - '0') - (str[0] - '0');
            }else{
                fim = (str[0] - '0') + (str[2] - '0');
            }
        }
        cout << fim << endl;
    }
}