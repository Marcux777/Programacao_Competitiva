#include <bits/stdc++.h>

using namespace std;

int main()
{
//	freopen("saida.txt","w",stdout);
	long long int A[61];
	int n,X;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	    A[1]=1;
	    A[0]=0;
		cin>>X;
		for(int K=2;K<=X+1;K++)
		{
			A[K]=A[K-2]+A[K-1];
		}
		cout<<"Fib("<<X<<") = "<<A[X]<<endl;
	}
}