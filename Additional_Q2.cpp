/*
Q2: Shortest Path in Grid
You are given a weighted grid size of m x n. Each cell contains a non-negative cost. Interpret the grid as a
graph where each cell is a node and edges exist between adjacent horizontal/vertical cells with weights
equal to the destination cell cost.
Task: Determine the minimum total cost from (0,0) to (m-1,n-1) using Dijkstra.
Example:
Input: grid=[[1,2,3],[4,5,6],[7,8,9]]
Output: 21
*/

// Time Complexity: O(m*n*log(m*n)), Space Complexity: O(m*n)

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;                     // grid dimensions

    int grid[100][100];
    for (int i = 0; i < m; i++)        // read grid
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    int dist[100][100];
    int visited[100][100] = {0};

    // initialize distances
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = 1e9;

    // min-heap: (cost, row, col)
    priority_queue<
        tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>
    > pq;

    dist[0][0] = grid[0][0];           // start cost
    pq.push({dist[0][0], 0, 0});       // push start

    int dr[4] = {1, -1, 0, 0};         // row moves
    int dc[4] = {0, 0, 1, -1};         // col moves

    while (!pq.empty()) {
        auto [cost, r, c] = pq.top();
        pq.pop();                      // extract min

        if (visited[r][c]) continue;
        visited[r][c] = 1;             // mark visited

        // explore neighbors
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                int newCost = cost + grid[nr][nc];  // moving cost = destination cell value

                if (newCost < dist[nr][nc]) {
                    dist[nr][nc] = newCost;         // update dist
                    pq.push({newCost, nr, nc});     // push neighbor
                }
            }
        }
    }

    cout << dist[m-1][n-1];            // final answer
    return 0;
}
