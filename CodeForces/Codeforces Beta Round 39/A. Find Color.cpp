#include <bits/stdc++.h>

using namespace std;

int main(){
	int x,y;
	cin>>x>>y;
	int dist = ceil(sqrt(x*x + y*y));
	if((x==0 && y == 1) || (x == 0 && y ==-1)|| dist == sqrt(x*x + y*y)){
		cout << "black\n";
	}else{
		if((y == 0 && x == 1) || (y == 0 && x == -1)){
			cout <<"white\n";
		}else{
			if((x<0 && y < 0) || (x > 0 && y > 0)){
				if(dist&1){
					cout<<"black\n";
				}else{
					cout << "white\n";
				}
			}else{
				if(dist&1){
					cout<<"white\n";
				}
				else{
					cout << "black\n";
				}
			}
		}
	}
}