/*
Q4: Number of Islands
You are given a 2D grid of size M x N consisting of characters '0' and '1'. A group of connected '1's
horizontally or vertically represents a piece of land, forming an island.
Task: Count the total number of islands present in the grid using BFS/DFS.
Example:
Input: grid=[[1,1,0],[0,1,0],[1,0,1]]
Output: 3
*/

// Time Complexity: O(M*N), Space Complexity: O(M*N)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS to cover the entire island
void bfs(int sr, int sc, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
    queue<pair<int,int>> q;
    q.push({sr, sc});
    vis[sr][sc] = true;                  // mark start cell

    int dr[4] = {-1, 1, 0, 0};           // row directions -> up, right, down, left
    int dc[4] = {0, 0, -1, 1};           // col directions -> up, right, down, left

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {    // traverse neighbors
            int nr = r + dr[i];
            int nc = c + dc[i];

            // valid land neighbor
            if (nr >= 0 && nr < grid.size() &&
                nc >= 0 && nc < grid[0].size() &&
                grid[nr][nc] == 1 && !vis[nr][nc]) 
            {
                vis[nr][nc] = true;      // mark visited
                q.push({nr, nc});        // add to queue
            }
        }
    }
}

int main() {
    int M, N;
    cin >> M >> N;                        // grid dimensions

    vector<vector<int>> grid(M, vector<int>(N));

    // read grid
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> vis(M, vector<bool>(N, false));
    int islands = 0;                       // count of islands

    // count islands
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1 && !vis[i][j]) {
                bfs(i, j, grid, vis);     // explore island
                islands++;                // increment count
            }
        }
    }

    cout << islands;
    return 0;
}
