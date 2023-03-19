#include <iostream>
using namespace std;

void sabre(int m[][1000], int l, int c){
    int x = 0, y = 0;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            if(m[i][j] == 42){
                if(m[i][j-1] == 7 && m[i][j+1] == 7 && m[i-1][j] == 7 && m[i-1][j-1] == 7 && m[i-1][j+1] == 7 && m[i+1][j] == 7 && m[i+1][j-1] == 7 && m[i+1][j+1] == 7){
                    x = i+1;
                    y = j+1;
                }
            }
        }
    }
    printf("%d %d\n", x, y);
}

int main(){
    int n,m;
    int s[1000][1000];
    scanf("%d %d", &n, &m);
    //vai ler a matriz
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> s[i][j];
        }
    }
    sabre(s, n, m);
}
