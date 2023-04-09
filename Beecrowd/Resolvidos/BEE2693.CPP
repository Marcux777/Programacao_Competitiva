#include <bits/stdc++.h>

using namespace std;

struct Pessoa
{
    string nome;
    char local;
    int custo;
};

int regiao(char a){
    if(a == 'L'){
        return 1;
    }else{
        if(a == 'N'){
            return 2;
        }else{
            if(a == 'O'){
                return 3;
            }else{
                return 4;
            }
        }
    }
}

bool comp(Pessoa a, Pessoa b){
    if(a.custo != b.custo){
        return a.custo < b.custo;
    }else{
        if(a.local != b.local){
            return regiao(a.local) < regiao(b.local);
        }else{
            return a.nome < b.nome;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("saida.txt", "w", stdout);
    int t;
    while (cin >> t)
    {
        vector<Pessoa> v;
        while (t--)
        {
            Pessoa a;
            cin >> a.nome >> a.local >> a.custo;
            v.push_back(a);
        }
        sort(v.begin(), v.end(), comp);
        for(auto it : v){
            cout << it.nome << endl;
        }
    }
}