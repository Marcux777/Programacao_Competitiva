#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<string, int> st;
    while (n--)
    {
        string nome;
        cin >> nome;
        if (st.find(nome) == st.end())
        {
            st.insert({nome, 1});
            cout << "OK\n";
        }
        else
        {
            cout << nome << st[nome] << endl; 
            st[nome]++;
        }
    }
}