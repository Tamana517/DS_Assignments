/*
Q: Write a program to implement the following graph algorithms
1. Breadth First Search (BFS)
*/

#include <iostream>
using namespace std;

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    int adj[100][100];        // adjacency list using array + degree[]
    int degree[100] = {0};    // count of neighbors for each node
    int visited[100] = {0};   // visited array

    // set all adjacency entries to 0 (no neighbors yet)
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
    cout << "Enter starting vertex for BFS: ";
    cin >> start;

    int queue[100];                // manual queue
    int front = 0, rear = 0;       // queue pointers

    visited[start] = 1;
    queue[rear++] = start;         // enqueue start node

    cout << "\nBFS Traversal: ";

    while (front < rear) {         // queue not empty
        int node = queue[front++]; // dequeue
        cout << node << " ";

        // explore adjacency list of current node
        for (int i = 0; i < degree[node]; i++) {
            int neigh = adj[node][i];

            if (!visited[neigh]) {
                visited[neigh] = 1;
                queue[rear++] = neigh;  // enqueue neighbor
            }
        }
    }

    cout << endl;
    return 0;
}
