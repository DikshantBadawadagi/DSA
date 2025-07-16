#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
    vector<vector<int>> adjMatrix = {
        {0,       INF, 2,   INF, 1,   INF},
        {INF,     0,   INF, 4,   INF, 5},
        {INF,     INF, 0,   INF, 3,   1},
        {INF,     INF, INF, 0,   3,   INF},
        {INF,     INF, INF, INF, 0,   INF},
        {INF,     INF, INF, INF, INF, 0}
    };

    int n = adjMatrix.size();

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (adjMatrix[i][k] < INF && adjMatrix[k][j] < INF) {
                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adjMatrix[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << adjMatrix[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
