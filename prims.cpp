#include <iostream>
#include <vector>
#include <queue>

typedef std::pair<int, int> pii; // Pair of (weight, vertex)

void prim(const std::vector<std::vector<pii>>& graph) {
    int start_vertex = 0; // Select any starting vertex
    int n = graph.size();

    std::vector<bool> visited(n, false);
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    pq.push(std::make_pair(0, start_vertex));

    while (!pq.empty()) {
        int weight = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();

        if (visited[vertex])
            continue;

        visited[vertex] = true;
        std::cout << "Edge: " << vertex << " - " << vertex << ", Cost: " << weight << std::endl;

        for (const auto& neighbor : graph[vertex]) {
            int next_vertex = neighbor.second;
            int next_weight = neighbor.first;
            if (!visited[next_vertex])
                pq.push(std::make_pair(next_weight, next_vertex));
        }
    }
}

// Example usage
int main() {
    int n; // Number of vertices
    std::cout << "Enter the number of vertices: ";
    std::cin >> n;

    std::vector<std::vector<pii>> graph(n);
    int edges;
    std::cout << "Enter the number of edges: ";
    std::cin >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        std::cout << "Enter edge " << i+1 << " (source, destination, weight): ";
        std::cin >> u >> v >> weight;
        graph[u].push_back(std::make_pair(weight, v));
        graph[v].push_back(std::make_pair(weight, u));
    }

    prim(graph);

    return 0;
}
