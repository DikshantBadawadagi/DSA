#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        int n, s, m;
        cin >> n >> s >> m;
        vector<pair<int, int>> task(n);
        for (int i = 0; i < n; i++) {
            int first, second;
            cin >> first >> second;
            task[i] = make_pair(first, second);
        }

        bool found = false;

        // Check the first and last task directly
        if (task[0].first >= s) {
            cout << "YES" << endl;
            continue;
        }
        if (10 - task[n - 1].second >= s) {
            cout << "YES" << endl;
            continue;
        }

        // Check the gaps between tasks
        for (int i = 0; i < n - 1; i++) {
            if (task[i + 1].first - task[i].second >= s) {
                cout << "YES" << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "NO" << endl;
        }
    }
    return 0;
}
