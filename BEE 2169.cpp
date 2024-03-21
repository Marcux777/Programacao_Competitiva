#include <bits/stdc++.h>

using namespace std;

unordered_map<string, double> armas;
unordered_map<string, int> monstros;

void inicia()
{
    armas["HANDGUN"] = 2;
    armas["RED9"] = 3.5;
    armas["BLACKTAIL"] = 3.5;
    armas["MATILDA"] = 2;
    armas["HANDCANNON"] = 60;
    armas["STRIKER"] = 12;
    armas["TMP"] = 1.2;
    armas["RIFLE"] = 12;
    monstros["GANADOS"] = 50;
    monstros["COBRAS"] = 40;
    monstros["ZEALOT"] = 75;
    monstros["COLMILLOS"] = 60;
    monstros["GARRADOR"] = 125;
    monstros["LASPLAGAS"] = 100;
    monstros["GATLINGMAN"] = 150;
    monstros["REGENERATOR"] = 250;
    monstros["ELGIGANTE"] = 500;
    monstros["DR.SALVADOR"] = 300;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    inicia();
    int qa, qb, qm;
    while (cin >> qa)
    {
        string s; int c; 
        map<string, double> bolsa;
        map<string, double> cabana;
        while (qa--)
        {
            cin >> s >> c;
            bolsa[s] = armas[s]*c;
        }
        cin >> qm;
        while (qm--){
            cin >> s >> c;
            cabana[s] = monstros[s]*c;
        }
    }
}