#include <bits/stdc++.h> 
using namespace std;
int main(){
	int s,t,f;
	cin >> s >> t >> f;
	s = s+t;
	if(s > 24){
		s = s%24;
	}
	s += f;
	if(s < 0){
		s += 24;
	}
	cout << s << endl;
}

