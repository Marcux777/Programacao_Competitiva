#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	while(n--){
		string a,b;
		cin >> a >> b;
		if(a == "tesoura"){
			//tesoura ganha
			if(b == "papel"){
				cout << "rajesh" << endl;
			}
			if(b == "lagarto"){
				cout << "rajesh" << endl;
			}
			if(b == "tesoura"){
				cout << "empate" << endl;
			}
			//tesoura perde
			if(b == "spock"){
				cout << "sheldon" << endl;
			}
			if(b == "pedra"){
				cout << "sheldon" << endl;
			}
		}
		if(a == "papel"){
			//papel ganha
			if(b == "pedra"){
				cout << "rajesh" << endl;
			}
			if(b == "spock"){
				cout << "rajesh" << endl;
			}
			//papel perde
			if(b == "tesoura"){
				cout << "sheldon" << endl;
			}
			if(b == "lagarto"){
				cout << "sheldon" << endl;
			}
				//empate
			if(b == "papel"){
				cout << "empate" << endl;
			}
		}
		if(a == "pedra"){
			//pedra ganha
			if(b == "lagarto"){
				cout << "rajesh" << endl;
			}
			if(b == "tesoura"){
				cout << "rajesh" << endl;
			}
			//pedra perde
			if(b == "papel"){
				cout << "sheldon" << endl;
			}
			if(b == "spock"){
				cout << "sheldon" << endl;
			}
				//empate
			if(b == "pedra"){
				cout << "empate" << endl;
			}
		}
		if(a == "lagarto"){
			//lagarto ganha
			if(b == "spock"){
				cout << "rajesh" << endl;
			}
			if(b == "papel"){
				cout << "rajesh" << endl;
			}
			//lagarto perde
			if(b == "tesoura"){
				cout << "sheldon" << endl;
			}
			if(b == "pedra"){
				cout << "sheldon" << endl;
			}
				//empate
			if(b == "lagarto"){
				cout << "empate" << endl;
			}
		}
		if(a == "spock"){
			//spock ganha
			if(b == "tesoura"){
				cout << "rajesh" << endl;
			}
			if(b == "pedra"){
				cout << "rajesh" << endl;
			}
			//spock perde
			if(b == "papel"){
				cout << "sheldon" << endl;
			}
			if(b == "lagarto"){
				cout << "sheldon" << endl;
			}
				//empate
			if(b == "spock"){
				cout << "empate" << endl;
			}
		}
	}
}
