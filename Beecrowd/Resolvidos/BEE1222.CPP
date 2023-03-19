#include<bits/stdc++.h>

using namespace std;
int main(){
     int numPalavras, linhas, paginas, caracs, i;
     int maxLinhas, maxCarac;
     string palavra;

     while(cin >> numPalavras >> maxLinhas >> maxCarac){
     	for(i = 1, linhas = paginas = caracs = 0; i <= numPalavras; i++){
     		cin >> palavra;
     		
     		caracs += palavra.size();
     
            if(caracs == maxCarac){
            	caracs = 0;
            	linhas++;
            }
     		else{
				if(caracs > maxCarac){
					caracs = palavra.size() + 1;
					linhas++;
				}else{
					if(i < numPalavras){
						caracs++;
						if(caracs == maxCarac){
							caracs = 0;
							linhas++;
						}
					}
				}
			}	 
     		
     		if(linhas == maxLinhas){
     			linhas = 0;
     			paginas++;
     		}
     	}

     	if(linhas > 0 || caracs > 0) paginas++;
     	cout << paginas << endl;
     }

	 return 0;
}
