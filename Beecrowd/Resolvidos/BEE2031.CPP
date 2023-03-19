#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    string jogada1, jogada2;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> jogada1;
        cin >> jogada2;
        if (jogada1 == "papel"){
            if(jogada2 == "papel"){
                cout << "Ambos venceram" << endl;
            } else{
                if (jogada2 == "pedra"){
                    cout << "Jogador 2 venceu" << endl;
                } else{
                    if(jogada2 == "ataque"){
                        cout << "Jogador 2 venceu" << endl;
                    }
                } 
            } 
        }
        else if (jogada1 == "pedra"){
            if(jogada2 == "papel"){
                cout << "Jogador 1 venceu" << endl;
            } else{
                if (jogada2 == "pedra"){
                    cout << "Sem ganhador" << endl;
                } else{
                    if(jogada2 == "ataque"){
                        cout << "Jogador 2 venceu" << endl;
                    }
                } 
            } 
        }
        else if (jogada1 == "ataque"){
            if(jogada2 == "papel"){
                cout << "Jogador 1 venceu" << endl;
            } else{
                if(jogada2 == "pedra"){
                    cout << "Jogador 1 venceu" << endl;
                }else{
                    if(jogada2 == "ataque"){
                        cout << "Aniquilacao mutua" << endl;
                    }
                } 
            } 
        }
    }
}