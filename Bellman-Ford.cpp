#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9; // Set a high value for infinity

vector<int> bellman_ford(int n, vector<vector<pair<int, int>>> adj_list, int start) {
    vector<int> dist(n, INF);
    dist[start] = 0;

    // Relax all edges n - 1 times
    for (int i = 1; i <= n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (auto v_pair : adj_list[u]) {
                int v = v_pair.first;
                int weight = v_pair.second;
                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    // Check for negative weight cycles
    for (int u = 0; u < n; u++) {
        for (auto v_pair : adj_list[u]) {
            int v = v_pair.first;
            int weight = v_pair.second;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                cout << "Graph contains negative weight cycle" << endl;
                return vector<int>();
            }
        }
    }

    return dist;
}

int main() {
    int n = 5; // Number of vertices
    vector<vector<pair<int, int>>> adj_list(n);

    // Add edges to the adjacency list
    adj_list[0].push_back(make_pair(1, -1));
    adj_list[0].push_back(make_pair(2, 4));
    adj_list[1].push_back(make_pair(2, 3));
    adj_list[1].push_back(make_pair(3, 2));
    adj_list[1].push_back(make_pair(4, 2));
    adj_list[3].push_back(make_pair(1, 1));
    adj_list[3].push_back(make_pair(2, 5));
    adj_list[4].push_back(make_pair(3, -3));

    int start = 0; // Start vertex for shortest paths
    vector<int> shortest_paths = bellman_ford(n, adj_list, start);

    // Print shortest distances from start vertex
    for (int i = 0; i < n; i++) {
        cout << "Shortest distance from vertex " << start << " to " << i << " is " << shortest_paths[i] << endl;
    }

    return 0;
}

