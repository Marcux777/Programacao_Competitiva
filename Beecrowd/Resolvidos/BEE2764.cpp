#include <iostream>
#include <string>
using namespace std;
int main()
{
    string Data;
    string Dataf;
    char aux[2] = {'/', '-'};
    cin >> Data;
    cout << Data[3] << Data[4] << aux[0] << Data[0] << Data[1] << aux[0] << Data[6] << Data[7] << endl;
    cout << Data[6] << Data[7] << aux[0] << Data[3] << Data[4] << aux[0] << Data[0] << Data[1] << endl;
    cout << Data[0] << Data[1] << aux[1] << Data[3] << Data[4] << aux[1] << Data[6] << Data[7] << endl;
}
