#include <iostream>
#include <vector>

using namespace std;

// Function to check if a color can be assigned to a vertex
bool isSafe(int v, const vector<vector<int>>& graph, const vector<int>& color, int c) {
    for (int adjacent : graph[v]) {
        if (color[adjacent] == c) {
            return false;
        }
    }
    return true;
}

// Function to perform graph coloring using Backtracking and Branch and Bound
bool graphColoring(const vector<vector<int>>& graph, int numColors, vector<int>& color, int v = 0) {
    if (v == graph.size()) {
        return true;  // All vertices have been colored
    }

    for (int c = 1; c <= numColors; ++c) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoring(graph, numColors, color, v + 1)) {
                return true;
            }
        }
    }

    return false;  // No valid coloring found
}

int main() {
    int numColors = 3;

    vector<vector<int>> graph = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3, 4},
        {0, 2, 4},
        {2, 3}
    };

    vector<int> color(graph.size(), 0);

    if (graphColoring(graph, numColors, color)) {
        cout << "Solution found. Vertex colors: ";
        for (int c : color) {
            cout << c << " ";
        }
        cout << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
