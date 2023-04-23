#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	float P1, P2, media;
	cin >> P1;
	cout << setprecision(2) << fixed;
	while (P1 > 10 || P1 < 0)
	{
		cout << "nota invalida" << endl;
		cin >> P1;
	}
	cin >> P2;
	while (P2 > 10 || P2 < 0)
	{
		cout << "nota invalida" << endl;
		cin >> P2;
	}
	media = (P1 + P2) / 2;
	cout << "media = " << media << endl;
}