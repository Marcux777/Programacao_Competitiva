#include <iostream>
using namespace std;
int main()
{
	int a, b, c, d, mini, minf, mints;
	cin >> a >> b >> c >> d;
	mini = a * 60 + b;	 // minuto inicial
	minf = c * 60 + d;	 // minuto final
	mints = mini - minf; // qnts minutos
	if (mini == minf)
	{
		cout << "O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)" << endl;
	}
	else
	{
		if (mini < minf)
		{
			mints = minf - mini; // qnts minutos
			cout << "O JOGO DUROU " << mints / 60 << " HORA(S) E " << mints % 60 << " MINUTO(S)" << endl;
		}
		else
		{
			mints = (minf - mini) + 24 * 60; // qnts minutos
			cout << "O JOGO DUROU " << mints / 60 << " HORA(S) E " << mints % 60 << " MINUTO(S)" << endl;
		}
	}
}