#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    // freopen("saida.txt","w", stdout);
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int M, N;
        cin >> M >> N;

        // cria o dicionário
        map<string, string> dici;
        for (int i = 0; i < M; i++)
        {
            string jap, port;
            cin >> jap;
            cin.ignore(); // ignora a quebra de linha
            getline(cin, port);
            dici[jap] = port;
        }

        // traduz a letra da música
        for (int i = 0; i < N; i++)
        {
            string line;
            getline(cin, line);

            string word;
            bool first = true;

            for (char c : line)
            {
                if (c == ' ')
                {
                    if (!first)
                    {
                        cout << ' ';
                    }
                    first = false;

                    if (dici.find(word) != dici.end())
                    {
                        cout << dici[word];
                    }
                    else
                    {
                        cout << word;
                    }

                    word.clear();
                }
                else
                {
                    word += c;
                }
            }

            if (!first)
            {
                cout << ' ';
            }

            if (dici.find(word) != dici.end())
            {
                cout << dici[word];
            }
            else
            {
                cout << word;
            }

            cout << endl;
        }

        cout << endl;
    }

    return 0;
}
