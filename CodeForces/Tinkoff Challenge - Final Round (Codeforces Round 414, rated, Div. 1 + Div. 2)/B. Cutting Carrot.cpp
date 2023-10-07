#include <bits/stdc++.h>

using namespace std;


int main(){
	cout << fixed <<setprecision(12);
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	//freopen("saida.txt", "w", stdout);
	int n,h;
	cin>>n>>h;
	for(int i = 1;i < n; i++){
		cout<<sqrt(i / (n*1.0)) * h;
		if(i == n-1){
			cout<<endl;
		}else{
			cout<<" ";
		}
	}
}