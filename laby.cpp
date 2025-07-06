#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    queue<pair<int, int>> q;

    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};
    string dir = "URDL";

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> move(n, vector<char>(m, '.'));

    pair<int, int> start, end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                q.push({i, j});
                vis[i][j] = 1;
                start = {i, j};
            }
            if (grid[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    bool found = false;

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        if (grid[row][col] == 'B') {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] != '#') {
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
                parent[nrow][ncol] = {row, col};
                move[nrow][ncol] = dir[i];
            }
        }
    }

    if (!found) {
        cout << "NO" << endl;
        return 0;
    }

    // Reconstruct path
    vector<char> res;
    int x = end.first, y = end.second;

    while (make_pair(x, y) != start) {
        res.push_back(move[x][y]);
        auto [px, py] = parent[x][y];
        x = px;
        y = py;
    }

    reverse(res.begin(), res.end());

    cout << "YES" << endl;
    cout << res.size() << endl;
    for (char c : res) cout << c;
    cout << endl;

    return 0;
}
