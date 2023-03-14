#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack <char> pilha;
    char exp[1001];
    while(scanf("%s", &exp) != EOF){
        while(pilha.size() > 0){
            pilha.pop();
        }
        for(int i = 0; exp[i]; i++){
            if(exp[i] == '('){
                pilha.push(exp[i]);
            }else{
                if(exp[i] == ')'){
                    if(pilha.size() > 0){
                        pilha.pop();
                    }else{
                        pilha.push(exp[i]);
                    }
                }
            }
        }
        if(pilha.size() == 0){
            cout << "correct" << endl;
        } else{
            cout << "incorrect" << endl;
        }
    }
}