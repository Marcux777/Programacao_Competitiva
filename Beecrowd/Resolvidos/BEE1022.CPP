#include <iostream>
using namespace std;

int mdc(int a, int b)
{
	if(a<0)
		a = -a;
	if(b<0)
		b = -b;
	if(a%b == 0)
		return b;
	else
		return mdc(b,a%b);
}

int main(){
    int n, n1, n2, d1, d2;
    char op, inutil;
    int den, num;
    cin >> n;
    while(n--){

        cin >> n1 >> inutil >> d1 >> op >> n2 >> inutil >> d2;
        if(op == '+'){
            num = n1*d2 + n2*d1;
            den = d1*d2;
        }else{
            if(op == '-'){
                num = n1*d2 - n2*d1;
                den = d1*d2;
            }else{
                if(op == '*'){
                    num = n1*n2;
                    den = d1*d2;
                }else{
                    num = n1*d2;
                    den = n2*d1;
                }
            }
        }
        int div = mdc(num, den);
        cout << num << "/" << den << " = " << num/div << "/" << den/div << endl;

    }
}