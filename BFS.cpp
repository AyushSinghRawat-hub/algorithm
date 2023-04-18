#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> adj;  // adjacency list
vector<bool> visited;     // keeps track of visited nodes

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        // visit node v
        cout << v << " ";

        // add unvisited neighbors of v to the queue
        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // initialize adjacency list and visited array
    adj.resize(n);
    visited.resize(n, false);

    // read input and build adjacency list
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // run bfs starting at node 0
    bfs(0);

    return 0;
}

