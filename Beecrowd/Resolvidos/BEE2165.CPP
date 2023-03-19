#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(){
    char T[505];
    int i;
    scanf("%[^\n]", T);
    for(i = 0; T[i]; i++){
    }
    if(i > 140){
        cout << "MUTE" << endl;
    }else{
        cout << "TWEET" << endl;
    }
}