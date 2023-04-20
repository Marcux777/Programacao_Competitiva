#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        string word = "";
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                reverse(word.begin(), word.end());
                result += word + " ";
                word = "";
            } else {
                word += s[i];
            }
        }
        
        // Inverte a última palavra
        reverse(word.begin(), word.end());
        result += word;
        
        return result;
    }
};

int main() {
    Solution sol;
    string s = "Let's take LeetCode contest";
    cout << sol.reverseWords(s) << endl;
    return 0;
}
