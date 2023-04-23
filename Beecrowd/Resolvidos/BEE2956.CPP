#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double b, h;
	cin >> b >> h;
	cout << setprecision(5) << fixed;
	cout << "Concluimos que, dado o limite da entrada, a resposta seria:  y = f(x) = " << b * h / 2.0 << "." << endl;
}
