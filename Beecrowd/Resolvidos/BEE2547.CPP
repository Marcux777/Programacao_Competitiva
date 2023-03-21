#include<iostream>
using namespace std;
int main(){
   int t,min,max, c;
   while(cin>> t >> min >> max){
        c = 0;
        while(t--){
            int a;
            cin>>a;
            if(a>=min&&a<=max){
                c++;
            }
        }
        cout << c << endl;
    }
    return 0;
}