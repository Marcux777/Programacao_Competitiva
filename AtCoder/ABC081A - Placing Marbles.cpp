#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string s;
    cin >> s;
    int cont = count(s.begin(), s.end(), '1');
    cout << cont << endl;
}