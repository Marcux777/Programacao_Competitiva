#include <iostream>
using namespace std;
int main(){
    int n, dir;
    char pos[1000];
    cin >> n;
    while(n != 0){
        dir = 0;
        cin >> pos;
        for(int i = 0; i < n; i++){
            if(pos[i] == 'D'){
                dir++;
            } else{
                dir--;
            }
        }
        if(dir%4 == 0 || dir == 0){
            cout << 'N' << endl;
        } else if (dir%2 == 0){
            cout << 'S' << endl;
        } else if (dir == -1 || dir/-3 == 0){
            cout << 'L' << endl;
        } else {
            cout << 'O' << endl;
        }
        cin >> n;
    }
}