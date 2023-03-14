#include <iostream>
#include <string>
using namespace std;
int main(){
    int diai,diaf, hi, hf, mi,mf,si,sf;
    int ts1, ts2, tempo, w,x,y,z;
    string inutil;
    cin >> inutil >> diai;
    cin >> hi >> inutil >> mi >> inutil >> si; //hora inicial, minuto inicial e segundo inicial
    cin >> inutil >> diaf;
    cin >> hf >> inutil >> mf >> inutil >> sf; //hora final, minuto final e segundo final
    ts1 = (diai*24*60*60)+(hi*60*60)+(mi*60)+si; //tempo inicial em segundos
    ts2 = (diaf*24*60*60)+(hf*60*60)+(mf*60)+sf; //tempo final em segundos
    tempo = ts2 - ts1;
    w = tempo/(24*60*60);
    x = (tempo%(24*60*60))/(60*60);
    y = ((tempo%(24*60*60))%(60*60))/60;
    z = ((tempo%(24*60*60))%(60*60))%60;
    cout << w << " dia(s)" << endl;
    cout << x << " hora(s)" << endl;
    cout << y << " minuto(s)" << endl;
    cout << z << " segundo(s)" << endl;

}