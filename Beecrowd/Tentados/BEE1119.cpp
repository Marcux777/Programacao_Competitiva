#include <iostream>
#include <list>

using namespace std;

int main() {
    freopen("saida.txt", "w", stdout);
    int n, k, m;

    while (cin >> n >> k >> m && (n != 0 || k != 0 || m != 0)) {
        list<int> people;
        for (int i = 1; i <= n; i++) {
            people.push_back(i);
        }

        list<int>::iterator it1 = people.begin(), it2 = --people.end();
        while (people.size() > 0) {
            for (int i = 0; i < k-1; i++) {
                ++it1;
                if (it1 == people.end()) {
                    it1 = people.begin();
                }
            }
            for (int i = 0; i < m-1; i++) {
                if (it2 == people.begin()) {
                    it2 = --people.end();
                } else {
                    --it2;
                }
            }

            cout << *it1;
            if (it1 != it2) {
                cout << "," << *it2;
                people.erase(it2--);
            }
            people.erase(it1++);
            if (people.size() > 0) {
                cout << ",";
            }
        }
        cout << endl;
    }

    return 0;
}
