#include <bits/stdc++.h>

using namespace std;

int main(){
	set<char> st = {'A','O', 'Y','E','U','I', 'a', 'o', 'y', 'e', 'u', 'i'};
	string s, str;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(st.find(s[i]) == st.end()){
			str+='.';
			str+=tolower(s[i]);
		}
	}
	cout << str << endl;
}