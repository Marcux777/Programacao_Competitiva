#include <iostream>
#include <math.h>
using namespace std;

unsigned long long sd[1000000];

void num_divine(){
    unsigned long long i, j;

	for (i = 1; i <= 1000000; i++)
		for (j = i; j <= 1000000; j += i)
			sd[j] += i;

	for (i = 2; i <= 1000000; i++)
		sd[i] += sd[i - 1];
}
int main(){
    unsigned long long n;
    num_divine();
    while(cin >> n && n){
        cout << sd[n] << endl;
    }
}