#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	//freopen("saida.txt", "w", stdout);
	int a, v;
	int cont = 0;
	while(cin >> a >> v && a && v){
		vector<int> vet[101];
		vector<int> resp;
		for(int i = 0; i < v; i++){
			int x, y;
			cin >> x >> y;
			vet[x].push_back(y);
			vet[y].push_back(x);
		}
		int tam = vet[0].size();
		for(int i = 1; i <= a; i++){
			if(vet[i].size() > tam){
				tam = vet[i].size();
			}
		} 
		for(int i = 1; i <= a; i++){
			if(vet[i].size() == tam){
				resp.push_back(i);
			}
		}
		cout << "Teste " << ++cont << endl;
		for(int i = 0; i < resp.size(); i++){
			cout << resp[i] << " ";
		}
		cout << endl << endl;
	}
}
