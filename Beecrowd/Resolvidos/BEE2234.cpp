#include <iostream>
using namespace std;

int main(){
    int hotdogs, participants;
    cin >> hotdogs >> participants;
    double avg = (double)hotdogs / participants;
    printf("%.2f\n", avg);
    return 0;
}
