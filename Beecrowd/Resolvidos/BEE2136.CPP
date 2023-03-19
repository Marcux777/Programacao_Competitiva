#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int maior_nome = -1;
	set <pair<string, string>> a,n;
	string nome, resp, amigo;
	cin >> nome;
	while(nome != "FIM"){
		cin >> resp;
		if(resp == "YES"){
			a.insert(make_pair(nome,resp));
			if((int)nome.size() > maior_nome){
				maior_nome = nome.size();
				amigo = nome;
			}
			
		}else{
			n.insert(make_pair(nome,resp));
		}
		cin >> nome;
	}
	bool t = true;
	for (auto &i: a){
		if(t && i.second == "YES"){
			t = false;
			//amigo = i.first;
		}
        cout << i.first << endl;
    }
    for (auto &i: n) {
        cout << i.first << endl;
    }
    cout << endl;
    cout << "Amigo do Habay:" << endl;
    cout << amigo << endl;
}
