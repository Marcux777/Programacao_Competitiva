#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    float n1,n2,n3,n4,media, exame,mf;
    cin >> n1 >> n2 >> n3 >> n4;
    media = (n1*2 + n2*3 + n3*4 + n4*1)/(2+3+4+1);
    cout << "Media: " << setprecision(1) << fixed << media << endl;
    if (media >= 7){
        cout << "Aluno aprovado." << endl;
    }
    else if (media < 5){
        cout << "Aluno reprovado." << endl;
    } else if (media >= 5 && media <= 6.9){
        cout << "Aluno em exame." << endl;
        cin >> exame;
        cout << "Nota do exame: " << setprecision(1) << fixed << exame << endl;
        mf = (exame + media)/2;

        if (mf > 5){
            cout << "Aluno aprovado." << endl;
        } else {
            cout << "Aluno reprovado." << endl;
        }
        cout << "Media final: " << setprecision(1) << fixed << mf << endl;
    }
}