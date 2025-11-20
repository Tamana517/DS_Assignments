/*
Q: Write a program to implement the following graph algorithms:
2. Depth First Search (DFS)
*/

#include <iostream>
using namespace std;

// DFS function
void dfs(int node, int adj[][100], int degree[], int visited[]) {
    visited[node] = 1;                  // mark current node visited
    cout << node << " ";                // print node during traversal

    // explore all neighbors
    for (int i = 0; i < degree[node]; i++) {
        int neigh = adj[node][i];
        if (!visited[neigh]) {
            dfs(neigh, adj, degree, visited);  // recursive call to visit neighbor
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    int adj[100][100];        // adjacency list using array + degree[]
    int degree[100] = {0};    // degree[u] = number of neighbors in adj[u][]
    int visited[100] = {0};   // visited array


    // initialize adjacency list to 0
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u][degree[u]++] = v;   // add v to u's list
        adj[v][degree[v]++] = u;   // add u to v's list (undirected)
    }

    int start;
    cout << "Enter starting vertex for DFS: ";
    cin >> start;

    cout << "\nDFS Traversal: ";
    dfs(start, adj, degree, visited);  // begin DFS traversal from start vertex
    cout << endl;

    return 0;
}
