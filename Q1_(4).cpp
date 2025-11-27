/*
Q: Write a program to implement the following graph algorithms
4. Dijkstra's Shortest Path Algorithm
*/

#include <iostream>
using namespace std;

#define INF 1000000      // represent infinity

int main() {
    int N, E, K;
    cout << "Enter number of nodes: ";
    cin >> N;
    cout << "Enter number of edges: ";
    cin >> E;

    int adj[100][100];       // adjacency matrix
    int visited[100] = {0};  // visited nodes

    // initialize adjacency matrix
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            adj[i][j] = INF;       // no edge

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;             // directed edge u->v
    }

    cout << "Enter starting node K: ";
    cin >> K;

    int dist[100];             // distance from K
    for (int i = 0; i < N; i++)
        dist[i] = INF;
    dist[K] = 0;               // distance to start node is 0

    // Dijkstra's algorithm
    for (int count = 0; count < N; count++) {
        int u = -1;
        int minDist = INF;

        // find unvisited node with minimum distance
        for (int i = 0; i < N; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break;     // all reachable nodes processed
        visited[u] = 1;

        // relax all neighbors of u
        for (int v = 0; v < N; v++) {
            if (!visited[v] && adj[u][v] != INF) {
                if (dist[u] + adj[u][v] < dist[v])
                    dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    // find maximum distance
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (dist[i] == INF) {    // unreachable node
            ans = -1;
            break;
        }
        if (dist[i] > ans) ans = dist[i];
    }

    cout << "\nTime for all nodes to receive signal: " << ans << endl;

    return 0;
}
