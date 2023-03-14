#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    string s, trad, nome;
    map <string, string> mp;
    cin >> n;
    while(n--){
        cin >> s;
        cin.ignore();
        getline(cin, trad);
        mp[s] = trad;
    }
    cin >> m;
    while(m--){
        cin.ignore();
        getline(cin, nome);
        cin >> s;

        cout << nome << endl;
        cout << mp.find(s)->second << endl << endl;

    }
}