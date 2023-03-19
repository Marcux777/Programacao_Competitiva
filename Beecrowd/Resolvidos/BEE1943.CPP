#include <iostream>
using namespace std;
int main(){
	int X;
	cin>>X;
	if(X==1)cout<<"Top 1"<<endl;
	if(X>1 && X<=3)cout<<"Top 3"<<endl;
	if(X>3 && X<=5)cout<<"Top 5"<<endl;
	if(X>5 && X<=10)cout<<"Top 10"<<endl;
	if(X>10 && X<=25)cout<<"Top 25"<<endl;
	if(X>25 && X<=50)cout<<"Top 50"<<endl;
	if(X>50 && X<=100)cout<<"Top 100"<<endl;
}