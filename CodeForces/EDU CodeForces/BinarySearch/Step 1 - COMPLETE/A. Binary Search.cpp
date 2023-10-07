#include <iostream>
#include <vector>
 
using namespace std;
 
bool binarysearch(vector<int>&v, int l, int r, int x){
	if(l > r){
		return false;
	}
	int mid = l+(r-l)/2;
	if(v[mid] == x){
		return true;
	}
	if(v[mid] > x){
		return binarysearch(v, l, mid-1, x);
	}else{
		return binarysearch(v, mid + 1, r, x);
	}
}
 
int main(){
	int n, k;
	cin >> n >> k;
	vector<int>v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	for(int i = 0; i < k; i++){
		int x;
		cin >> x;
		if(binarysearch(v, 0, n-1, x)){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
}