#include <bits/stdc++.h>

using namespace std;

struct cow{
    int dia;
    string nome;
    int prod;
    cow(){
        dia = 0;
        prod = 0;
    }
};

int main(){
    ifstream cin("measurement.in");
    ofstream cout("measurement.out");
    int n; cin >> n;
    vector<cow> v(n);

    for(auto &i : v)
        cin >> i.dia >> i.nome >> i.prod;

    sort(v.begin(), v.end(), [](auto a, auto b){
        return a.dia < b.dia;
    });
    map<string, int> mp;
    mp["Bessie"] = 7;
    mp["Elsie"] = 7;
    mp["Mildred"] = 7;
    int ans = 0;
    set<string> prev_max_vacas = {"Bessie", "Elsie", "Mildred"};

    for (int i = 0; i < n; ++i) {
        mp[v[i].nome] += v[i].prod;

        int max_prod = max({mp["Bessie"], mp["Elsie"], mp["Mildred"]});
        set<string> curr_max_vacas;
        for (auto &p : mp) {
            if (p.second == max_prod) {
                curr_max_vacas.insert(p.first);
            }
        }

        if (curr_max_vacas != prev_max_vacas) {
            ans++;
            prev_max_vacas = curr_max_vacas;
        }
    }

    cout << ans << endl;
}