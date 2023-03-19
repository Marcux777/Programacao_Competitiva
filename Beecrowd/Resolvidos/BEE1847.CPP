#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    char feel;
    cin >> a >> b >> c;
    if (a > b && b <= c){
        feel = ')';
    } else if (a < b && b >= c){
        feel = '(';
    } else if (a < b && b < c && c-b < b-a){
        feel = '(';
    } else if (a < b && b < c && c-b >= b-a){
        feel = ')';
    } else if (a > b && b > c && c-b > b-a){
        feel = ')';
    } else if (a > b && b > c && b-c >= b-a){
        feel = '(';
    } else if (a == b && b < c){
        feel = ')';
    } else{
        feel = '(';
    }
    cout << ":" << feel << endl;
}