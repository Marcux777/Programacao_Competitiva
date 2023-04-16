#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0, r = n - 1;
        
        // Busca binária para encontrar a posição do caractere target ou da próxima letra maior do que target
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (letters[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        // Retorna o caractere na posição encontrada, ou o primeiro caractere do vetor caso a próxima letra seja maior do que a última letra do vetor
        return letters[l % n];
    }
};


int main()
{
    Solution s;
    vector<char> letters = {'e', 'e', 'e', 'e', 'e', 'e', 'n', 'n', 'n', 'n'};
    char target = 'e';
    cout << s.nextGreatestLetter(letters, target) << endl; // output: n
    return 0;
}
