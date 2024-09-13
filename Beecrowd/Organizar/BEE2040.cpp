#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool comp(pair<string, int> a, pair<string, int> b){
        return a.second > b.second;
}

int main()
{
    //freopen("saida.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n && n)
    {
        map<string, int> st;
        for (int i = 0; i < n; i++)
        {
            string time;
            int pontos;
            cin >> time >> pontos;
            st[time] = pontos;
        }
        for (int i = 0; i < n / 2; i++)
        {
            string time1, time2, placar;
            int placar1 = 0, placar2 = 0;
            cin >> time1 >> placar >> time2;
            bool isPlacar1 = true;
            for (int j = 0; j < placar.size(); j++)
            {
                if (placar[j] == '-')
                {
                    isPlacar1 = false;
                    continue;
                }
                if (isPlacar1)
                {
                    placar1 = placar1 * 10;
                    placar1 +=  (placar[j] - '0');
                }
                else
                {
                    placar2 = placar2 * 10;
                    placar2 +=  (placar[j] - '0');
                }
            }
            st[time1] += 3*placar1;
            st[time2] += 3*placar2;
            if(placar1 == placar2){
                st[time1]++;
                st[time2]++;
            }else{
                if(placar1 > placar2){
                    st[time1] += 5;
                }else{
                    st[time2] += 5;
                }
            }
        }
        vector<pair<string, int>>v(st.begin(), st.end());
        sort(v.begin(), v.end(), comp);
        if(v[0].first == "Sport"){
            cout << "O Sport foi o campeao com " << v[0].second << " pontos :D\n";
        }else{
            cout << "O Sport nao foi o campeao. O time campeao foi o "
            << v[0].first << " com " <<v[0].second << " pontos :(\n";
        }
        cout << endl;
    }
}