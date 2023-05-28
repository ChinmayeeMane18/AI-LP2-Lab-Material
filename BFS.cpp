#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform Breadth First Search
void bfs(int startVertex, vector<bool>& visited, const vector<vector<int>>& graph) {
    queue<int> q;
    q.push(startVertex);
    visited[startVertex] = true;

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";

        for (int i = 0; i < graph[vertex].size(); ++i) {
            int adjacentVertex = graph[vertex][i];
            if (!visited[adjacentVertex]) {
                visited[adjacentVertex] = true;
                q.push(adjacentVertex);
            }
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    // In a tree, the number of edges is always (vertices - 1)
    edges = vertices - 1;

    // Create an adjacency list representation of the tree
    vector<vector<int>> graph(vertices);
    cout << "Enter the edges (parent child):\n";
    for (int i = 0; i < edges; ++i) {
        int parent, child;
        cin >> parent >> child;
        graph[parent].push_back(child);
        graph[child].push_back(parent);
    }

    // Initialize visited array
    vector<bool> visited(vertices, false);

    cout << "Breadth First Traversal (starting from root): ";
    bfs(0, visited, graph);

    return 0;
}
