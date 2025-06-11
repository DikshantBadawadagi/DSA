#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    if(n == 1){
        cout << grid[0][0] << endl;
        return 0;
    }

    vector<string> curr(n), next(n);

    next[n-1] = string(1, grid[n-1][n-1]);
    for(int j = n - 2; j >= 0; j--) {
        next[j] = grid[n-1][j] + next[j+1];
    }

    for(int i = n - 2; i >= 0; i--) {
        curr[n-1] = grid[i][n-1] + next[n-1];
        for(int j = n - 2; j >= 0; j--) {
            char ch = grid[i][j];
            char downFirst = next[j][0];
            char rightFirst = curr[j+1][0];

            // Greedy check: only compare full strings if first characters equal
            if (downFirst < rightFirst) {
                curr[j] = ch + next[j];
            } else if (downFirst > rightFirst) {
                curr[j] = ch + curr[j+1];
            } else {
                string down = ch + next[j];
                string right = ch + curr[j+1];
                curr[j] = min(down, right);
            }
        }
        next = curr;
    }

    cout << curr[0] << endl;
}
