#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector <string> sv, sd;
    string s1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> s1;
            if(s1[1] == 'V'){
                sv.push_back(s1);
            }else{
                sd.push_back(s1);
            }
            
        }
    }
    sort(sv.begin(), sv.end());
    sort(sd.begin(), sd.end());
    for(auto it = sv.rbegin(); it != sv.rend(); it++){
        cout << *it << endl;
    }
    for(auto it = sd.rbegin(); it != sd.rend(); it++){
        cout << *it << endl;
    }
}