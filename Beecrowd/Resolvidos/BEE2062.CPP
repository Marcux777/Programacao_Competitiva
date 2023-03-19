#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string a, fim;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a.size() == 3 && a[0]=='U' && a[1] == 'R'){
            if(i < n-1){
                fim += "URI ";
            }else{
                fim += "URI";
            }
        }else{
            if(a.size() == 3 && a[0]=='O' && a[1] == 'B'){
                if(i < n-1){
                    fim += "OBI ";
                }else{
                    fim += "OBI";
                }
            }else{
                if(i < n-1){
                    fim += a + ' ';
                }else{
                    fim += a;
                }
            }
        }
    }
    cout << fim << endl;
}