/*
Q: Write a program to implement the following graph algorithms
3. (a) Minimum Spanning Tree (Kruskal)
*/

#include <iostream>
using namespace std;

struct Edge {
    int u, v, w;    // edge from u to v with weight w
};

int parent[100];    // parent array for union-find

// find parent of node u
int findParent(int u) {
    if (parent[u] == u) return u;
    return parent[u] = findParent(parent[u]);  // path compression
}

// union sets containing u and v
void unionSets(int u, int v) {
    int pu = findParent(u);
    int pv = findParent(v);
    parent[pu] = pv;
}

int main() {
    int N, E;
    cout << "Enter number of nodes: ";
    cin >> N;
    cout << "Enter number of edges: ";
    cin >> E;

    Edge edges[100];       // array to store edges

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    for (int i = 0; i < N; i++)
        parent[i] = i;     // initialize parent of each node

    // sort edges by weight using selection sort
    for (int i = 0; i < E-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < E; j++)
            if (edges[j].w < edges[minIdx].w)
                minIdx = j;
        swap(edges[i], edges[minIdx]);
    }

    int mstWeight = 0;    // total weight of MST

    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int pu = findParent(u);
        int pv = findParent(v);

        if (pu != pv) {      // if adding edge doesn't form cycle
            mstWeight += w;  // add edge weight to MST
            unionSets(u, v); // merge components
        }
    }

    cout << "\nTotal weight of MST: " << mstWeight << endl;
    return 0;
}
