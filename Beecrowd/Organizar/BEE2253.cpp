#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

bool is_valid_password(const string& password) {
    int n = password.size();
    bool has_upper = false;
    bool has_lower = false;
    bool has_digit = false;
    
    if (n < 6 || n > 32) {
        return false;
    }
    
    for (int i = 0; i < n; i++) {
        if (ispunct(password[i]) || isspace(password[i]) || iscntrl(password[i])) {
            return false;
        }
        
        if (isupper(password[i])) {
            has_upper = true;
        }
        else if (islower(password[i])) {
            has_lower = true;
        }
        else if (isdigit(password[i])) {
            has_digit = true;
        }
    }
    
    return has_upper && has_lower && has_digit;
}

int main() {
    string password;
    while (getline(cin, password)) {
        if (is_valid_password(password)) {
            cout << "Senha valida.\n";
        }
        else {
            cout << "Senha invalida.\n";
        }
        password.clear();
    }
    return 0;
}
