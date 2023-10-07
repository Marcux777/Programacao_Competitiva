#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int par1, impar1, par2, impar2;
		par1 = impar1 = par2 = impar2 = 0;
		for(int i = 1; i <= n; i++){
			int x;
			cin >> x;
			if(i&1){
				if(x&1)par1 = 1;
				else impar1 = 1;
			}else{
				if(x&1)par2 = 1;
				else impar2 = 1;
			}
		}
		if((impar1 && par1) || (impar2 && par2))
		{
			cout << "NO\n";
		}else{
			cout << "YES\n";
		}
	}
}