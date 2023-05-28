import heapq

def prim(graph):
    start_vertex = 0  # Select any starting vertex
    n = len(graph)

    visited = [False] * n
    pq = [(0, start_vertex)]
    heapq.heapify(pq)

    while pq:
        weight, vertex = heapq.heappop(pq)

        if visited[vertex]:
            continue

        visited[vertex] = True

        for neighbor, next_weight in graph[vertex]:
            if not visited[neighbor]:
                heapq.heappush(pq, (next_weight, neighbor))
                print(f"Edge: {vertex} - {neighbor}, Cost: {next_weight}")

# Example usage
n = int(input("Enter the number of vertices: "))
graph = [[] for _ in range(n)]

edges = int(input("Enter the number of edges: "))
for _ in range(edges):
    input_str = input("Enter edge (source, destination, weight): ")
    u, v, weight = map(int, input_str.split())
    graph[u].append((v, weight))
    graph[v].append((u, weight))

prim(graph)


#vertices - 4
#edges - 5
# 0 1 2
# 0 2 4
# 1 3 3
# 2 3 1
# 2 1 5