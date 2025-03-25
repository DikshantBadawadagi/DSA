#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int ans = 0;
    int startx, starty, endx, endy;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A') {
                startx = i;
                starty = j;
            }
            if(grid[i][j] == 'B') {
                endx = i;
                endy = j;
            }
        }
    }

    queue<pair<int, int>> q;
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> path(n, vector<char>(m, '.'));
    
    q.push({startx, starty});
    vis[startx][starty] = 1;
    
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    char dir[] = {'U', 'R', 'D', 'L'};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == endx && y == endy) {
            cout << "YES" << endl;
            goto construct_path;
        }

        for(int i = 0; i < 4; i++) {
            int nrow = x + drow[i];
            int ncol = y + dcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] != '#' && !vis[nrow][ncol]) {
                vis[nrow][ncol] = 1;
                parent[nrow][ncol] = {x, y};
                q.push({nrow, ncol});
                path[nrow][ncol] = dir[i];
            }
        }
    }

    cout << "NO" << endl;
    return 0;

construct_path:
    vector<char> res;
    int ind1 = endx, ind2 = endy;
    
    while (ind1 != startx || ind2 != starty) {
        res.push_back(path[ind1][ind2]);
        int px = parent[ind1][ind2].first;
        int py = parent[ind1][ind2].second;
        ind1 = px;
        ind2 = py;
    }

    reverse(res.begin(), res.end());
    cout << res.size() << endl;
    for(auto i : res) {
        cout << i;
    }
    cout << endl;

    return 0;
}
