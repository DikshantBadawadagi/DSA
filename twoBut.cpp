#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    if (n >= m) {
        cout << n - m << endl;
        return 0;
    }


    const int LIMIT = 20001;
    vector<int> dist(LIMIT, -1);
    queue<int> q;

    dist[n] = 0;
    q.push(n);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == m) {
            cout << dist[u] << endl;
            return 0;
        }

        int v_red = u * 2;
        if (v_red < LIMIT && dist[v_red] == -1) {
            dist[v_red] = dist[u] + 1;
            q.push(v_red);
        }

        int v_blue = u - 1;
        if (v_blue > 0 && dist[v_blue] == -1) {
            dist[v_blue] = dist[u] + 1;
            q.push(v_blue);
        }
    }

    return 0;
}