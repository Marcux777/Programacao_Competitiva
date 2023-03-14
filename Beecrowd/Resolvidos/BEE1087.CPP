#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x1,x2,y1,y2;
    int di,dj;
    cin >> x1 >> y1 >> x2 >> y2;
    while(x1 || y1 || x2 || y2){
        di=fabs(x1-x2);
        dj=fabs(y1-y2); 
		if(x1==x2&&y1==y2){
			printf("0\n");
		}else{
			if(di==dj||x1==x2||y1==y2){
				printf("1\n");
			}else{
				printf("2\n");
			}
		}
		cin >> x1 >> y1 >> x2 >> y2;
    }
}
