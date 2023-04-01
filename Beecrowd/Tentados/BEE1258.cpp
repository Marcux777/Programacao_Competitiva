#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    string nome, cor;
    char a;
    map <string, pair<string, char>> branco, vermelho;
    while(cin >> t && t){
        while(t--){
            cin.ignore();
            getline(cin, nome);
            cin >> cor >> a;
            if(cor == "branco"){
                branco[nome] = make_pair(cor, a);
            }else{
                vermelho[nome] = make_pair(cor, a);
            }
        }
        for(auto it = branco.begin(); it != branco.end(); it++){
            if(it->second.second == 'P'){
                cout << it->second.first << " " << it->second.second << " " << it->first << endl;
            }
        }
        for(auto it = branco.begin(); it != branco.end(); it++){
            if(it->second.second == 'M'){
                cout << it->second.first << " " << it->second.second << " " << it->first << endl;
            }
        }
        for(auto it = branco.begin(); it != branco.end(); it++){
            if(it->second.second == 'G'){
                cout << it->second.first << " " << it->second.second << " " << it->first << endl;
            }
        }
        for(auto it = vermelho.begin(); it != vermelho.end(); it++){
            if(it->second.second == 'P'){
                cout << it->second.first << " " << it->second.second << " " << it->first << endl;
            }
        }
        for(auto it = vermelho.begin(); it != vermelho.end(); it++){
            if(it->second.second == 'M'){
                cout << it->second.first << " " << it->second.second << " " << it->first << endl;
            }
        }
        for(auto it = vermelho.begin(); it != vermelho.end(); it++){
            if(it->second.second == 'G'){
                cout << it->second.first << " " << it->second.second << " " << it->first << endl;
            }
        }
        cout << endl;
        branco.clear();
        vermelho.clear();
    }

    
}