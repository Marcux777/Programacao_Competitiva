#include <iostream>

using namespace std;
int main()
{
    int j = 7;
    for (int i = 1; i < 10; i++)
    {
        cout << "I=" << i << " J=" << j << endl;
        cout << "I=" << i << " J=" << j - 1 << endl;
        cout << "I=" << i << " J=" << j - 2 << endl;
        j = j + 2;
        i++;
    }
}