#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    
    int lengthOfLastWord(string s) {
        vector <string> v;
        string aux;
        for(int i = 0; s[i]; i++){
            if(isalpha(s[i])){
                aux+=s[i];
            }else{
                if(!aux.empty()){
                    v.push_back(aux);
                    aux = "";
                }
                aux = "";
            }
        }
        if(!aux.empty()){
            v.push_back(aux);
        }
        string UltimaPalavra = *(v.rbegin());
        return UltimaPalavra.size();
    }
    
};

int main(){
    Solution s;
    string str = "Hello World";
    int res = s.lengthOfLastWord(str);
    cout << res << endl; // deve imprimir 5
    return 0;
}
