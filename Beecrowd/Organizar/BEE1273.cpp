#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("saida.txt", "w", stdout);
    int n;
    bool primeiro = true;
    while (cin >> n && n)
    {
        if (!primeiro)
        {
            cout << endl;
        }
        primeiro = false;
        vector<string> words;
        int max_len = 0;
        for (int i = 0; i < n; i++)
        {
            string word;
            cin >> word;
            words.push_back(word);
            max_len = max(max_len, (int)word.length());
        }
        for (string word : words)
        {
            cout << string(max_len - word.length(), ' ') << word << endl;
        }
    }
    return 0;
}