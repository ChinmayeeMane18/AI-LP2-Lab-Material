#include <iostream>
#include <vector>

using namespace std;

// Function to perform Depth First Search recursively
void dfs(int vertex, vector<bool>& visited, vector<vector<int>>& graph) {
    visited[vertex] = true;
    cout << vertex << " ";

    for (int i = 0; i < graph[vertex].size(); ++i) {
        int adjacentVertex = graph[vertex][i];
        if (!visited[adjacentVertex]) {
            dfs(adjacentVertex, visited, graph);
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

    cout << "Depth First Traversal (starting from root): ";
    dfs(0, visited, graph);

    return 0;
}
