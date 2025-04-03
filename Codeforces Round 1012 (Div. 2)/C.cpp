#include <bits/stdc++.h>
using namespace std;

struct Table {
    int x, y;
    bool operator<(Table other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> t(n);
        for (int i = 0; i < n; i++) {
            cin >> t[i];
        }

        set<Table> empty_tables;
        set<Table> partially_occupied;

        queue<pair<int, Table>> q_bfs;
        q_bfs.push({0, {0, 0}});
        empty_tables.insert({0, 0});

        for (int i = 0; i < n; i++) {
            Table chosen;
            if (t[i] == 0) {
                while (!q_bfs.empty()) {
                    auto [dist, table] = q_bfs.front();
                    if (empty_tables.count(table)) {
                        chosen = table;
                        q_bfs.pop();
                        break;
                    }
                    q_bfs.pop();

                    for (int dx = -1; dx <= 1; dx++) {
                        for (int dy = -1; dy <= 1; dy++) {
                            if (dx == 0 and dy == 0) continue;
                            Table neighbor = {table.x + dx, table.y + dy};
                            if (empty_tables.count(neighbor) == 0 and
                                partially_occupied.count(neighbor) == 0) {
                                empty_tables.insert(neighbor);
                                q_bfs.push({dist + 1, neighbor});
                            }
                        }
                    }
                }
            } else {
                while (!q_bfs.empty()) {
                    auto [dist, table] = q_bfs.front();
                    if (empty_tables.count(table) or partially_occupied.count(table)) {
                        chosen = table;
                        q_bfs.pop();
                        break;
                    }
                    q_bfs.pop();

                    for (int dx = -1; dx <= 1; dx++) {
                        for (int dy = -1; dy <= 1; dy++) {
                            if (dx == 0 and dy == 0) continue;
                            Table neighbor = {table.x + dx, table.y + dy};
                            if (empty_tables.count(neighbor) == 0 and
                                partially_occupied.count(neighbor) == 0) {
                                empty_tables.insert(neighbor);
                                q_bfs.push({dist + 1, neighbor});
                            }
                        }
                    }
                }
            }

            empty_tables.erase(chosen);
            partially_occupied.insert(chosen);

            cout << 3*chosen.x + 1 << " " << 3*chosen.y + 1 << "\n";
        }
    }

    return 0;
}
