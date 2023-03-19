#include <iostream>
#include <string.h>
using namespace std;
void paridade(char *x){
    int c = 0;
    for(int i = 0; x[i]; i++){
        if(x[i] == '1'){
            c++;
        }
    }
    if(c%2 == 0){
        strcat(x, "0\0");
    } else {
        strcat(x, "1\0");
    }
    cout << x << endl;

}
int main(){
    char bit[200];
    cin >> bit;
    paridade(bit);
}