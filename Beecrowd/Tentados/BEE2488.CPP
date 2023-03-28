#include <iostream>
#include <map>
#include <math.h>
#include <iomanip>

using namespace std;

double calculo(double x1, double y1, double x2, double y2){
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}



int main(){
    cout << fixed << setprecision(2);
    map <pair<double, double>, pair<double, double>> plano;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        double x1,y1;
        cin >> x1 >> y1;
        plano[{x1, y1}] = {0, 0};
    }
    for(int i = 0; i < m; i++){
        double x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        auto it = plano.find({x1,y1});
        it->second = {x2, y2};
        cout << calculo(it->first.first, it->first.second, it->second.first, it->second.second) << endl;
    }
}