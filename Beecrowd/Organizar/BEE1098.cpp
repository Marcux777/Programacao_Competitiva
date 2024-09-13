#include <iostream>
using namespace std;
int main()
{
    float i = 0, j = 1;
    for (int k = 0; k <= 10; k++)
    {
        cout << "I=" << i << " J=" << j << endl;
        cout << "I=" << i << " J=" << j + 1 << endl;
        cout << "I=" << i << " J=" << j + 2 << endl;
        i += 0.2;
        j += 0.2;
    }
}