/*
Q: Write a program to implement the following graph algorithms
3. (b) Minimum Spanning Tree (Prim)
*/

#include <iostream>
using namespace std;

#define INF 1000000    // represent infinity

int main() {
    int N, E;
    cout << "Enter number of nodes: ";
    cin >> N;
    cout << "Enter number of edges: ";
    cin >> E;

    int adj[100][100];         // adjacency matrix
    int visited[100] = {0};    // track visited nodes
    int key[100];              // key[i] = minimum weight edge to include node i in MST

    // initialize adjacency matrix
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            adj[i][j] = INF;

    cout << "Enter edges for an undirected graph (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;         // edge from u to v
        adj[v][u] = w;         // edge from v to u (undirected)
    }

    // initialize key values
    for (int i = 0; i < N; i++)
        key[i] = INF;

    key[0] = 0;                // start from node 0
    int mstWeight = 0;

    // construct MST
    for (int count = 0; count < N; count++) {
        int u = -1;
        int minKey = INF;

        // find unvisited node with minimum key
        for (int i = 0; i < N; i++)
            if (!visited[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }

        visited[u] = 1;        // include u in MST
        mstWeight += key[u];   // add weight

        // update key values of neighbors
        for (int v = 0; v < N; v++)
            if (!visited[v] && adj[u][v] < key[v])
                key[v] = adj[u][v];
    }

    cout << "\nTotal weight of MST: " << mstWeight << endl;
    return 0;
}
