#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
#define endl '\n'
#define f first
#define s second
#define all(x) (x).begin(), (x).end() //obter um intervalo que abrange todo o contêiner
#define fi(x) find()
#define sz(x) ((int)(x).size()) // tamanho
#define pb push_back
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define vll vector<long long>
#define PI 3.14159265358979323846

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        bool a = true;
        for(int i = 0; i < 10; i++){
            if((n+1)% 3 == 0){
                n++;
            }
            else if((n-1)% 3 == 0){
                n--;
            }else{
                if(i%2 == 0){
                    n--;
                }else{
                    n++;
                }
            }
            if(n%3 == 0 && i%2 == 0){
                cout << "First" << endl;
                a = false;
                break;
            }
        }
        if(a) cout << "Second" << endl;
    }

}