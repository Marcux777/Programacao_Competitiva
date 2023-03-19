#include <iostream>
using namespace std;
int main()
{
	int t,i,n,passos=0,j;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
		for(j=n/2;j<n;j++)
		{
			passos++;
		}
		cout<<passos<<endl;
		passos=0;
	}
}