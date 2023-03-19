#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    while (n--) {
        int l;
        cin >> l;
        
        int hash = 0;
        
        for (int i = 0; i < l; i++) {
            string s;
            cin >> s;
            
            for (int j = 0; j < s.size(); j++) {
                hash += s[j] - 'A' + i + j;
            }
        }
        
        cout << hash << endl;
    }
    
    return 0;
}
