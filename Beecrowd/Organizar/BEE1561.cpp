#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("saida.txt", "w", stdout);
    string timeStr, x;
    char horas[2], minutos[2];
    int hora, minuto;
    char binhoras[4], binminutos[6], i;

    while (cin >> timeStr)
    {
        // Separando as horas e minutos
        horas[0] = timeStr[0];
        horas[1] = timeStr[1];
        minutos[0] = timeStr[3];
        minutos[1] = timeStr[4];

        string mtz[15];
        mtz[0] =  " ____________________________________________";
        mtz[1] =  "|                                            |";
        mtz[2] =  "|    ____________________________________    |_";
        mtz[3] =  "|   |                                    |   |_)";
        mtz[4] =  "|   |   8         4         2         1  |   |";
        mtz[5] =  "|   |                                    |   |";
        mtz[6] =  "|   |                                    |   |";
        mtz[7] =  "|   |                                    |   |";
        mtz[8] =  "|   |                                    |   |";
        mtz[9] =  "|   |                                    |   |";
        mtz[10] = "|   |                                    |   |";
        mtz[11] = "|   |   32    16    8     4     2     1  |   |_";
        mtz[12] = "|   |____________________________________|   |_)";
        mtz[13] = "|                                            |";
        mtz[14] = "|____________________________________________|";


        x = horas[0];
		x += horas[1];
		hora = stoi(x);
		for(i = 0; i < 4; i++)
		{
			binhoras[i] = ' ';
		}
		for(i = 0; hora > 0; i++)
		{
			binhoras[i] = hora%2;
			if(binhoras[i] == 1)
			{
				binhoras[i] = 'o';
			}
			else
			{
				binhoras[i] = ' ';
			}
			hora/= 2;		
		}
		// minutos
		x= minutos[0];
		x+= minutos[1];
		minuto = stoi(x);
		for(i = 0; i < 6; i++)
		{
			binminutos[i] = ' ';	
		}
		for(i = 0; minuto > 0; i++)
		{
			binminutos[i] = minuto%2;
			if(binminutos[i] == 1)
			{
				binminutos[i] = 'o';
			}
			else
			{
				binminutos[i] = ' ';
			}
			minuto/= 2;		
		}
		mtz[6][38] = binhoras[0];// 1
		mtz[6][28] = binhoras[1];// 2
		mtz[6][18] = binhoras[2];// 4
		mtz[6][8] = binhoras[3]; // 8
		// horas
		mtz[9][38] = binminutos[0];// 1
		mtz[9][32] = binminutos[1];// 2
		mtz[9][26] = binminutos[2];// 4
		mtz[9][20] = binminutos[3]; // 8
		mtz[9][14] = binminutos[4];// 16
		mtz[9][8] = binminutos[5];// 32

        // Imprimindo o relógio
        for (int i = 0; i < 15; i++)
            cout << mtz[i] << endl;

        cout << endl;
    }

    return 0;
}
