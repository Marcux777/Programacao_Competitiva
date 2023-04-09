#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n = s.length();
        unordered_set<char> seen;
        int i = 0, j = 0, maxLen = 0;
        
        // Percorre a string com uma janela deslizante
        while (i < n && j < n) {
            if (seen.count(s[j]) == 0) {
                // Se o caractere s[j] ainda não foi visto, adiciona-o ao conjunto e expande a janela
                seen.insert(s[j++]);
                maxLen = max(maxLen, j - i);
            } else {
                // Se o caractere s[j] já foi visto, remove-o do conjunto e diminui a janela
                seen.erase(s[i++]);
            }
        }
        
        return maxLen;
    }
};

// Função principal para testar a solução do problema 3
int main() {
    Solution sol;
    
    // Exemplos de entrada
    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";
    
    // Testa a solução para cada exemplo de entrada
    cout << "s1: " << sol.lengthOfLongestSubstring(s1) << endl; // Esperado: 3
    cout << "s2: " << sol.lengthOfLongestSubstring(s2) << endl; // Esperado: 1
    cout << "s3: " << sol.lengthOfLongestSubstring(s3) << endl; // Esperado: 3
    
    return 0;
}
