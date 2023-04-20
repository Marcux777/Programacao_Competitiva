#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        return reverse(s.begin(), s.end());
    }
};

int main()
{
    Solution solucao;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    solucao.reverseString(s);
    for (auto i : s)
    {
        cout << i;
    }
    cout << endl;
    return 0;
}
