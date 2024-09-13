#include <iostream>
using namespace std;
int main()
{
    int H, E, A, O, W, X;
    int exbem, exmal;
    cin >> H >> E >> A >> O >> W >> X;
    exbem = H + E + A + X;
    exmal = O + W;
    if (exbem >= exmal)
    {
        cout << "Middle-earth is safe." << endl;
    }
    else
    {
        cout << "Sauron has returned." << endl;
    }
}
