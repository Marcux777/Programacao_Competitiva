#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
    freopen("saida.txt", "w", stdout);

	cin >> n;
	cin.ignore();
	while(n--){
		string compras, aux;
        getline(cin, compras);
        istringstream ss(compras); // cria um stream de leitura para a lista
		set <string> lista_de_compras;
		
		while(ss >> aux){
            lista_de_compras.insert(aux);
        }
        int cont = lista_de_compras.size();
		for (string i : lista_de_compras) {
            if(cont > 1){
                cout << i << " ";
            }else{
                cout << i << endl;
            }
            cont--;
        }
        //cout << endl;
		compras.clear();
		lista_de_compras.clear();

	}
	return 0;
}
