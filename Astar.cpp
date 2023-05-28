#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <functional>

using namespace std;

struct Node {
    vector<vector<int>> state;
    int cost;
    int heuristic;
    Node* parent;

    Node(const vector<vector<int>>& _state, int _cost, int _heuristic, Node* _parent = nullptr)
        : state(_state), cost(_cost), heuristic(_heuristic), parent(_parent) {}

    bool operator==(const Node& other) const {
        return state == other.state;
    }
};

// Function to calculate the heuristic (Misplaced tiles)
int calculateHeuristic(const vector<vector<int>>& state, const vector<vector<int>>& goal) {
    int misplaced = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (state[i][j] != goal[i][j]) {
                misplaced++;
            }
        }
    }
    return misplaced;
}

// Function to generate possible moves from the current state
vector<vector<vector<int>>> generateMoves(const Node* node) {
    vector<vector<vector<int>>> moves;
    vector<vector<int>> state = node->state;
    int dx[] = {-1, 1, 0, 0};  // Possible movements: up, down, left, right
    int dy[] = {0, 0, -1, 1};

    int x, y;
    // Find the empty space (0 value)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (state[i][j] == 0) {
                x = i;
                y = j;
                break;
            }
        }
    }

    // Generate possible moves by swapping the empty space with adjacent tiles
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
            vector<vector<int>> newState = state;
            swap(newState[x][y], newState[nx][ny]);
            moves.push_back(newState);
        }
    }

    return moves;
}

// A* algorithm implementation
void solvePuzzle(const vector<vector<int>>& initial, const vector<vector<int>>& goal) {
    priority_queue<Node*, vector<Node*>, function<bool(Node*, Node*)>> pq(
        [](Node* a, Node* b) {
            return (a->cost + a->heuristic) > (b->cost + b->heuristic);
        }
    );

    Node* start = new Node(initial, 0, calculateHeuristic(initial, goal));
    pq.push(start);

    unordered_set<Node*> visited;
    visited.insert(start);

    while (!pq.empty()) {
        Node* current = pq.top();
        pq.pop();

        if (current->heuristic == 0) {
            cout << "Solution found!" << endl;
            return;
        }

        vector<vector<vector<int>>> moves = generateMoves(current);
        for (const auto& move : moves) {
            int moveCost = current->cost + 1;
            int moveHeuristic = calculateHeuristic(move, goal);
            Node* newNode = new Node(move, moveCost, moveHeuristic, current);

            if (!visited.count(newNode)) {
                pq.push(newNode);
                visited.insert(newNode);
            }
        }
    }

    cout << "No solution found!" << endl;
}

int main() {
    vector<vector<int>> initial = {
        {1, 2, 3},
        {0, 4, 6},
        {7, 5, 8}
    };

    vector<vector<int>> goal = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };

    solvePuzzle(initial, goal);

    return 0;
}

