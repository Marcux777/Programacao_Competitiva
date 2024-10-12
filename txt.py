# Read input values
import sys
import threading


def main():
    import sys

    sys.setrecursionlimit(1 << 25)
    N, M = map(int, sys.stdin.readline().split())
    INF = float("inf")
    adj = [[INF] * N for _ in range(N)]
    for i in range(N):
        adj[i][i] = 0

    edge_list = []
    for _ in range(M):
        A_i, B_i, C_i = map(int, sys.stdin.readline().split())
        A_i -= 1
        B_i -= 1
        adj[A_i][B_i] = min(adj[A_i][B_i], C_i)
        adj[B_i][A_i] = min(adj[B_i][A_i], C_i)
        edge_list.append((A_i, B_i, C_i))

    Q = int(sys.stdin.readline())
    queries = []
    closure_indices = []
    for _ in range(Q):
        tmp = sys.stdin.readline().split()
        if tmp[0] == "1":
            i = int(tmp[1]) - 1
            queries.append(("1", i))
            closure_indices.append(i)
        else:
            x, y = int(tmp[1]) - 1, int(tmp[2]) - 1
            queries.append(("2", x, y))

    # Initial all-pairs shortest paths
    D = [row[:] for row in adj]
    N = len(adj)
    for k in range(N):
        for i in range(N):
            for j in range(N):
                if D[i][k] + D[k][j] < D[i][j]:
                    D[i][j] = D[i][k] + D[k][j]

    for query in queries:
        if query[0] == "2":
            x, y = query[1], query[2]
            dist = D[x][y]
            print(int(dist) if dist < INF else -1)
        else:
            # Edge closure
            idx = query[1]
            u, v, w = edge_list[idx]
            adj[u][v] = INF
            adj[v][u] = INF

            # Recompute all-pairs shortest paths
            D = [row[:] for row in adj]
            for k in range(N):
                for i in range(N):
                    for j in range(N):
                        if D[i][k] + D[k][j] < D[i][j]:
                            D[i][j] = D[i][k] + D[k][j]


threading.Thread(target=main).start()
