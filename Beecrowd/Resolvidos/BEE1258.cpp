#include <bits/stdc++.h>

using namespace std;

int ordem(pair<string, char> a){
    if(a.second == 'P'){
        return 1;
    }else{
        if(a.second == 'M'){
            return 2;
        }else{
            return 3;
        }
    }
}

bool comp(pair<string, char> a, pair<string, char> b){
    if(a.second == b.second){
        return a.first < b.first;
    }else{
        return ordem(a) < ordem(b);
    }
}

int main()
{
    int t;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("saida.txt", "w", stdout);
    string nome, cor;
    char a;
    vector<pair<string, char>> branco, vermelho;
    cin >> t;
    while (t)
    {
        while (t--)
        {
            cin.ignore();
            getline(cin, nome);
            cin >> cor >> a;
            if (cor == "branco")
            {
                branco.push_back(make_pair(nome, a));
            }
            else
            {
                vermelho.push_back(make_pair(nome, a));
            }
        }
        sort(branco.begin(), branco.end(), comp);
        sort(vermelho.begin(), vermelho.end(), comp);

        for(auto it = branco.begin(); it != branco.end(); it++){
            cout << "branco " << it->second << " " << it->first << endl;
        }
        for(auto it = vermelho.begin(); it != vermelho.end(); it++){
            cout << "vermelho " << it->second << " " << it->first << endl;
        }

        branco.clear();
        vermelho.clear();
        cin >> t;
        if (t)
        {
            cout << endl;
        }
    }
}