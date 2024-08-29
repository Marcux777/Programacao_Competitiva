#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	string s;
	int a,b,d;
	cin>>s>>a>>b>>d;
	int c=a+d;
	string vet[7] = {"newbie", "pupil", "specialist", "expert", "candidate master", "master", "grandmaster"};
	
	int pat, pbest;
	if(c<=1199)pat = 0;
	else if(c<=1399)pat = 1;
	else if(c<=1599)pat = 2;
	else if(c<=1899)pat = 3;
	else if(c<=2099)pat = 4;
	else if(c<=2399)pat = 5;
	else if(c>2399)pat = 6;
	
	if(b<=1199)pbest = 0;
	else if(b<=1399)pbest = 1;
	else if(b<=1599)pbest = 2;
	else if(b<=1899)pbest = 3;
	else if(b<=2099)pbest = 4;
	else if(b<=2399)pbest = 5;
	else if(b>2399)pbest = 6;
	//cout<<pat<<' '<<pbest<<endl;
	if(pat > pbest) cout<<vet[pat]<<endl;
	else cout<<"Think about it, you can do it!"<<endl;
}
