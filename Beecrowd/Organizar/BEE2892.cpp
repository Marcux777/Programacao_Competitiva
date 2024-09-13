#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 
long long lcm(int a, int b)
{
    int greater = max(a, b);
    int smallest = min(a, b);
    for (int i = greater; ; i += greater) {
        if (i % smallest  == 0)
            return i;
    }
}

int main(){
	//freopen("saida.txt", "w", stdout);
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int a, b, c;
	while(cin >> a >> b >> c && (a && b && c)){
		vector<int>dist;
		for(int i = 1; i*i <= a; i++){
			if(a%i==0){
				dist.push_back(i);
				if(a/i != i){
					dist.push_back(a/i);
				}
			}
		}
		vector<int> s;
		int l = lcm(b, c);
		for(auto x : dist){
			if(lcm(x, l) == a){
				s.push_back(x);
			}
		}
		sort(s.begin(), s.end());
		for(int i = 0; i < s.size(); i++){
			cout << s[i];
			if(i < s.size() - 1){
				cout << " ";
			}
		}
		cout << endl;
		
	}
}
