#include <iostream>
#include <string>
#include <vector>

using namespace std;

int find(const string &text, const string &pattern, int start)
{
    int n = text.size();
    int m = pattern.size();
    for (int i = start; i <= n - m; i++)
    {
        int j = 0;
        while (j < m && text[i + j] == pattern[j])
        {
            j++;
        }
        if (j == m)
        {
            return i;
        }
    }
    return -1;
}

void search_positions(string &text, vector<string> &words)
{
    vector<int> positions;
    text = " " + text + " ";
    for (string &word : words)
    {
        word = " " + word + " ";
        int pos = find(text, word, 0);
        while (pos != -1)
        {
            positions.push_back(pos);
            pos = find(text, word, pos + 1);
        }
        if (positions.empty()) //não achei a palavra
        {
            cout << -1 << endl;
        }
        else
        {
            for (int i = 0; i < positions.size(); i++)
            {
                cout << positions[i];
                if (i < positions.size() - 1)
                {
                    cout << " ";
                }
                else
                {
                    cout << endl;
                }
            }
        }
        positions.clear();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("saida.txt", "w", stdout);
    string text;
    getline(cin, text);

    int num_words;
    cin >> num_words;

    vector<string> words(num_words);
    for (int i = 0; i < num_words; i++)
    {
        cin >> words[i];
    }

    search_positions(text, words);

    return 0;
}
