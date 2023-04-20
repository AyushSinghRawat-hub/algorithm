#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii;

const int INF = numeric_limits<int>::max();

vector<int> dijkstra(vector<vector<pii>> graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto v : graph[u]) {
            int w = v.second;
            if (dist[u] + w < dist[v.first]) {
                dist[v.first] = dist[u] + w;
                pq.push(make_pair(dist[v.first], v.first));
            }
        }
    }
    return dist;
}

int main() {
    int n, m, start;
    cin >> n >> m >> start;
    vector<vector<pii>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    vector<int> dist = dijkstra(graph, start);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            cout << "INF" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
    return 0;
}

