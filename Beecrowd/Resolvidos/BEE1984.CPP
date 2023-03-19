#include <iostream>
using namespace std;
void inverte_num(long long int *x){
    while(*x > 0){
        cout << *x%10;
        *x/=10;
    }
    cout << endl;
}
int main(){
    long long int num;
    cin >> num;
    inverte_num(&num);
}
