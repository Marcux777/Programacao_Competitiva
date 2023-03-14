#include <iostream>
#include <queue>
using namespace std;
int main(){
    int card;
    queue <int> remanecentes;
    queue <int> descartadas;
    cin >> card;
    while(card != 0){
        while(remanecentes.size()){
            remanecentes.pop();
        }
        while(descartadas.size()){
            descartadas.pop();
        }
        for(int i = 1; i <= card; i++){
            remanecentes.push(i);
        }
        while(remanecentes.size() > 1){
            descartadas.push(remanecentes.front());
            remanecentes.pop();
            remanecentes.push(remanecentes.front());
            remanecentes.pop();
        }
        cout << "Discarded cards: ";
        while(descartadas.size()){
            cout << descartadas.front();
            descartadas.pop();
            if(descartadas.size()>=1){
                cout << ", ";
            }
        }
        cout << endl;
        cout << "Remaining card: " << remanecentes.front() << endl;
        cin >> card;
    }
}