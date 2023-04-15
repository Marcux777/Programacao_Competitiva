#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int V; // No. of vertices

    // Pointer to an array containing adjacency
    // lists
    vector<list<int>> adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    // function to add an edge to graph
    void addEdge(int v, int w)
    {
        adj[v].push_back(w); // Add w to v’s list.
    }

    // prints BFS traversal from a given source s
    void BFS(int s)
    {
        // Mark all the vertices as not visited
        vector<bool> visited;
        visited.resize(V, false);

        // Create a queue for BFS
        list<int> queue;

        // Mark the current node as visited and enqueue it
        visited[s] = true;
        queue.push_back(s);

        while (!queue.empty())
        {
            // Dequeue a vertex from queue and print it
            s = queue.front();
            cout << s << " ";
            queue.pop_front();

            // Get all adjacent vertices of the dequeued
            // vertex s. If a adjacent has not been visited,
            // then mark it visited and enqueue it
            for (auto adjacent : adj[s])
            {
                if (!visited[adjacent])
                {
                    visited[adjacent] = true;
                    queue.push_back(adjacent);
                }
            }
        }
    }
};

int main()