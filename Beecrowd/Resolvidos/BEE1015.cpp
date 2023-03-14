#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){
	double x1, y1,x2, y2, dist;
	
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	
	dist = sqrt(pow(x2-x1, 2.0) + pow(y2-y1, 2.0));
	
	cout << fixed << setprecision(4);
	cout << dist << endl;
	
	return 0;
}