#include<iostream>
#include<vector>
using namespace std;

void fw(vector<vector<long long>>&mat, long long n) {
    for(long long k = 0; k < n; k++) {
        for(long long i = 0; i < n; i++) {
            for(long long j = 0; j < n; j++) {
                if(mat[i][k] == 1e18 || mat[k][j] == 1e18) continue;
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
}

int main() {
    long long n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long>> mat(n, vector<long long>(n, 1e18));

    for(int i = 0; i < n; i++) {
        mat[i][i] = 0;
    }

    for(long long i = 0; i < m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        // Use 0-based indexing
        a--; b--;
        mat[a][b] = min(mat[a][b], c);
        mat[b][a] = min(mat[b][a], c);
    }

    fw(mat, n);

    while(q--) {
        long long a, b;
        cin >> a >> b;
        a--; b--; // Convert to 0-based indexing
        if(mat[a][b] == 1e18) cout << -1 << endl;
        else cout << mat[a][b] << endl;
    }

    return 0;
}
