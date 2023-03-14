#include <iostream>

using namespace std;

int main(){
	int Vinter = 0, Vgremio = 0, empate = 0, grenal, igrenal, ginter = 0, ggremio = 0;
	cin >> ginter;
	cin >> ggremio;
	if (ginter > ggremio){
		Vinter++;
	} else {
		if (ginter < ggremio){
			Vgremio ++;
		}
		if (ginter == ggremio){
			empate++;
		}
	}
	igrenal = 1;

	cout << "Novo grenal (1-sim 2-nao)" << endl;
	cin >> grenal;
	
	while (grenal != 2){
			igrenal++;
		cin >> ginter;
		cin >> ggremio;
		if (ginter > ggremio){
			Vinter++;
		} else {
			if (ginter < ggremio){
				Vgremio ++;
			}
			if (ginter == ggremio){
				empate++;
			}
		}
	cout << "Novo grenal (1-sim 2-nao)" << endl;
	cin >> grenal;
	}
	cout << igrenal << " grenais" << endl;
	cout << "Inter:" << Vinter << endl;
	cout << "Gremio:" << Vgremio << endl;
	cout << "Empates:" << empate << endl;
	if (Vinter > Vgremio){
		cout << "Inter venceu mais" << endl;
	} else {
		if (Vinter < Vgremio){
			cout << "Gremio venceu mais" << endl;
		}
		if (Vinter == Vgremio){
			cout << "Nao houve vencedor" << endl;
		}
	}
	
}