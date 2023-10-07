#include <bits/stdc++.h>

using namespace std;

#define int long long int

int f(int x){
	while(x){
		 
		 if(sqrt(x) == floor(sqrt(x))){ //achei meu x quadrado perfeito :)
			 return x;
		 }
		 x--;
	 }
	 return 1;
}

signed main()
{
     int n;
     cin>>n;
     int x = sqrt(f(n)); //faço a raiz do quadrado perfeito
     int resp = 4*x;
     int aux = n-(x*x);
     if(aux>0)
     {
          if(aux<=x)
			resp+=2;
          else
			resp+=4;
     }
     
     cout<<resp<<endl;
     
}