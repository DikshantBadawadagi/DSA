#include <bits/stdc++.h>
using namespace std;

// 8×8 board, 64 squares
const int N = 8;
vector<vector<int>> board(N, vector<int>(N, 0)); // Visit numbers
vector<vector<bool>> visited(N, vector<bool>(N, false));
vector<vector<int>> deg(N, vector<int>(N, 0));

// Possible knight moves, matching the correct solution
const int h[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int v[] = {1, 2, 2, 1, -1, -2, -2, -1};

// Check if position (r, c) is valid
bool is_valid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

// Precompute degrees
void init_degrees() {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            for (int i = 0; i < 8; i++) {
                int dx = x + h[i];
                int dy = y + v[i];
                if (is_valid(dx, dy)) {
                    deg[x][y]++;
                }
            }
        }
    }
}

// Mark a square and update degrees
void mark(int id, int r, int c) {
    board[r][c] = id;
    visited[r][c] = true;
    for (int i = 0; i < 8; i++) {
        int nr = r + h[i];
        int nc = c + v[i];
        if (is_valid(nr, nc) && !visited[nr][nc]) {
            deg[nr][nc]--;
        }
    }
}

// Unmark a square and revert degrees
void unmark(int r, int c) {
    board[r][c] = 0;
    visited[r][c] = false;
    for (int i = 0; i < 8; i++) {
        int nr = r + h[i];
        int nc = c + v[i];
        if (is_valid(nr, nc) && !visited[nr][nc]) {
            deg[nr][nc]++;
        }
    }
}

// Backtracking with Warnsdorff's heuristic
bool find_path(int r, int c, int step) {
    mark(step, r, c);
    if (step == N * N) {
        return true;
    }

    // Get all possible moves and their degrees
    vector<tuple<int, int, int>> next_moves;
    for (int i = 0; i < 8; i++) {
        int nr = r + h[i];
        int nc = c + v[i];
        if (is_valid(nr, nc) && !visited[nr][nc]) {
            next_moves.push_back({deg[nr][nc], nr, nc});
        }
    }

    // Sort by degree only (no tie-breaker)
    sort(next_moves.begin(), next_moves.end());

    // Try each move
    for (auto [degree, nr, nc] : next_moves) {
        if (find_path(nr, nc, step + 1)) {
            return true;
        }
    }

    unmark(r, c);
    return false;
}

int main() {
    init_degrees();
    int x, y;
    cin >> x >> y;
    // Adjust indexing to match correct solution: (x, y) -> (y-1, x-1)
    int r = y - 1;
    int c = x - 1;

    // Start at position (r, c)
    if (find_path(r, c, 1)) {
        // Print the board
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j];
                if (j < N - 1) cout << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}