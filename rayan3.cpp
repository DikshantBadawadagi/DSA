#include <iostream>
#include <vector>
using namespace std;

bool dfs(int row, int col, vector<string>& maze, vector<vector<int>>& vis) {
    if (vis[row][col] == 1) return false; // Already processed
    if (maze[row][col] == '?') {
        vis[row][col] = 1; // Mark '?' as visited
        return true;
    }

    vis[row][col] = 1; // Mark current cell as visited

    int nrow, ncol;
    if (maze[row][col] == 'U') {
        nrow = row - 1, ncol = col;
    } else if (maze[row][col] == 'D') {
        nrow = row + 1, ncol = col;
    } else if (maze[row][col] == 'L') {
        nrow = row, ncol = col - 1;
    } else if (maze[row][col] == 'R') {
        nrow = row, ncol = col + 1;
    } else {
        return false; // Invalid cell
    }

    // Bounds check and DFS recursion
    if (nrow >= 0 && nrow < maze.size() && ncol >= 0 && ncol < maze[0].length()) {
        if (dfs(nrow, ncol, maze, vis)) {
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    long long t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> maze(n);
        for (int i = 0; i < n; i++) {
            cin >> maze[i];
        }

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int ans = 0;

        // Iterate through all cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0) {
                    if (dfs(i, j, maze, vis)) {
                        ans++;
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
