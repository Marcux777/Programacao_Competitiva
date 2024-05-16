#include <iostream>
#include <vector>

using namespace std;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int N) : parent(N + 1), rank(N + 1, 0) {
        for (int i = 0; i <= N; i++) {
            parent[i] = i;  // Initially, each user is in their own set
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;  // Already connected

        // Union by rank
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootX] = rootY;
            if (rank[rootX] == rank[rootY]) {
                rank[rootY]++;
            }
        }
    }
};

int maxNewFriendships(int N, int M, vector<vector<int>>& friendships) {
    DSU dsu(N);

    // Merge existing friendships
    for (auto& friendship : friendships) {
        dsu.unionSets(friendship[0], friendship[1]);
    }

    // Count potential new friendships
    int count = 0;
    for (int user = 1; user <= N; user++) {
        int componentRoot = dsu.find(user);
        for (int friend1 = 1; friend1 <= N; friend1++) {
            if (dsu.find(friend1) == componentRoot && friend1 != user) {  // Same component
                for (int friend2 = friend1 + 1; friend2 <= N; friend2++) {
                    if (dsu.find(friend2) == componentRoot &&   // Same component
                        dsu.find(user) != dsu.find(friend2)) {  // Not already friends 
                        count++;
                    }
                }
            }
        }
    }

    return count / 2; 
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> friendships(M, vector<int>(2));
    for (int i = 0; i < M; i++) {
        cin >> friendships[i][0] >> friendships[i][1];
    }

    int result = maxNewFriendships(N, M, friendships);
    cout << result << endl;

    return 0;
}
