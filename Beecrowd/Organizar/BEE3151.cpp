#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int

struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {
    double A = (double)a.value / a.weight;
    double B = (double)b.value / b.weight;
    return A > B;
}

double fractionalKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compare);

    double total = 0.0;
    for (const Item& item : items) {
        if (capacity >= item.weight) {
            total += item.value;
            capacity -= item.weight;
        } else {
            total += (double)item.value * capacity / item.weight;
            break;
        }
    }

    return total;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<Item> items(n);
        for (int i = 0; i < n; i++) {
            cin >> items[i].value >> items[i].weight;
        }

        cout << fixed << setprecision(2);
        cout << fractionalKnapsack(items, x) << endl;
    }

    return 0;
}
