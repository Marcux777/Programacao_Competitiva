#include<iostream>
#include <iomanip>
using namespace std;

int main(){
    int cod;
    float quant;
    
    cin >> cod >> quant;
    
    if (cod == 1){
        quant *= 4.00;
    }else if(cod == 2){
        quant*= 4.50;
    } else if (cod == 3){
        quant*=5.00;
    } else if (cod == 4){
        quant *= 2.00;
    } else{
        quant *= 1.50;
    }
    cout <<"Total: R$ " << setprecision(2) << fixed << quant << endl;
    return 0;
    
}
