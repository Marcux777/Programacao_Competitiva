#include <iostream>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        return haystack.find(needle);
    }
};
// Teste:
int main()
{
    Solution x;
    string frase, procurada;
    frase = "leetcode";
    procurada = "leeto";
    cout << x.strStr(frase, procurada) << endl;
}