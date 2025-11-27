/*
Q3: Network Delay Time
You are given a directed weighted graph G(V, E) and an array times[] where times[i] = (u, v, w) represents
an edge from node u to node v with weight w.
Task: Given a starting node K, find how long it takes for all nodes to receive the signal.
If some nodes cannot be reached, return -1.
Example:
Input: N=4, K=2, times=[[2,1,1],[2,3,1],[3,4,1]]
Output: 2
*/

// Time Complexity: O(E*log(N)), Space Complexity: O(N+E)

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    int N, E, K;
    cin >> N >> E >> K;                   // number of nodes, edges, start node

    vector<vector<pair<int,int>>> adj(N+1);  // adjacency list: (neighbor, weight)

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;              // directed edge u -> v with weight w
        adj[u].push_back({v, w});
    }

    const int INF = 1e9;
    vector<int> dist(N+1, INF);          // shortest time to reach each node

    // Dijkstra's algorithm: min-heap stores (current_cost, node)
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[K] = 0;
    pq.push({0, K});                      // start from node K

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (cost > dist[u]) continue;     // skip outdated distance

        // relax all outgoing edges from current node
        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (cost + w < dist[v]) {
                dist[v] = cost + w;       // update shortest time
                pq.push({dist[v], v});    // enqueue neighbor
            }
        }
    }

    // compute network delay: max shortest-path time
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == INF) {             // unreachable node
            cout << -1;
            return 0;
        }
        ans = max(ans, dist[i]);
    }

    cout << ans;                          // total time for all nodes to receive signal
    return 0;
}
