/*
Q1: Graph Traversal Count
Given an undirected graph G(V, E) with V representing the number of vertices numbered from 0 to V-1
and E representing the number of edges, what is the task? Each edge connects two vertices u and v.
Task: Determine the number of connected components in the graph.
Input format: V E followed by E lines of (u v) pairs.
Example:
Input: V=5, E=3, edges=[[0,1],[1,2],[3,4]]
Output: 2
*/

// Time Complexity: O(V+E), Space Complexity: O(V+E)

#include <iostream>
#include <vector>
using namespace std;

// DFS to mark all reachable nodes
void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[node] = true;                 // traverse adjacency list
    for (int nbr : adj[node]) {       
        if (!vis[nbr])
            dfs(nbr, adj, vis);       // explore neighbor
    }
}

int main() {
    int V, E;
    cin >> V >> E;                    // input V and E

    vector<vector<int>> adj(V);       // adjacency list
    vector<bool> vis(V, false);       // track visited nodes

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;                // read each edge
        adj[u].push_back(v);          // insert edge (u, v)
        adj[v].push_back(u);          // insert edge (v, u)  // undirected
    }

    int components = 0;               // count of components

    // count connected components
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {                // if not visited
            dfs(i, adj, vis);         // explore component
            components++;             // increment count
        }
    }

    cout << components;               // output result
    return 0;
}
