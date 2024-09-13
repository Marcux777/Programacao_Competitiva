#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>

using namespace std;

std::map<std::string, char> morseMap{
    {".-", 'a'},
    {"-...", 'b'},
    {"-.-.", 'c'},
    {"-..", 'd'},
    {".", 'e'},
    {"..-.", 'f'},
    {"--.", 'g'},
    {"....", 'h'},
    {"..", 'i'},
    {".---", 'j'},
    {"-.-", 'k'},
    {".-..", 'l'},
    {"--", 'm'},
    {"-.", 'n'},
    {"---", 'o'},
    {".--.", 'p'},
    {"--.-", 'q'},
    {".-.", 'r'},
    {"...", 's'},
    {"-", 't'},
    {"..-", 'u'},
    {"...-", 'v'},
    {".--", 'w'},
    {"-..-", 'x'},
    {"-.--", 'y'},
    {"--..", 'z'}};

// função para decodificar o código Morse
string decodeMorse(string morseCode)
{
    // resultado decodificado
    string result = "";
    vector<string> morse;
    string aux;
    std::stack<char> igual;
    std::stack<char> ponto;

    for (int i = 0; i < morseCode.size(); i++)
    {
        if (ponto.size() == 3 || ponto.size() == 6)
        {
            morse.push_back(aux);
            aux = "";
        }
        if (morseCode[i] == '=')
        {
            while (!ponto.empty())
            {
                ponto.pop();
            }
            igual.push(morseCode[i]);
        }
        else
        {
            ponto.push(morseCode[i]);
            if (igual.size() == 3)
            {
                aux += '-';
            }
            else
            {
                if (igual.size() == 1)
                {
                    aux += '.';
                }
            }
            while (!igual.empty())
            {
                igual.pop();
            }
        }
    }
    if (igual.size() == 1)
    {
        aux += '.';
    }
    else
    {
        aux += '-';
    }
    morse.push_back(aux);

    for (string i : morse)
    {
        result += morseMap[i];
    }
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] == NULL)
        {
            result[i] = ' ';
        }
    }
    return result;
}

int main()
{
    int t;
    // freopen("saida.txt", "w", stdout);
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string str;
        getline(cin, str);

        string resp = decodeMorse(str);

        cout << resp << endl;
    }
    return 0;
}
