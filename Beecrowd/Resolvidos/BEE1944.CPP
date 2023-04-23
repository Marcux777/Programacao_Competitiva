#include <iostream>
#include <stack>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
    string let, a;
    char a2;
    int n, cont = 0;
    stack<string> p;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        let.clear();
        if (p.empty())
        {
            p.push("FACE");
        }
        for (int j = 0; j < 4; j++)
        {
            cin >> a2;
            let.push_back(a2);
        }
        a = let;
        reverse(a.begin(), a.end());
        if (p.top() == a)
        {
            cont++;
            p.pop();
        }
        else
        {
            p.push(let);
        }
    }
    cout << cont << endl;
}