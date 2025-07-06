#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s_input;
        cin >> s_input;
        int n = s_input.size();
        vector<int> s(n);
        for (int i = 0; i < n; ++i) {
            s[i] = s_input[i] - '0';
        }

        int m;
        cin >> m;
        string l, r;
        cin >> l >> r;

        int mx = 0;
        bool found = false;

        for (int i = 0; i < m; ++i) {
            int li = l[i] - '0';
            int ri = r[i] - '0';
            int nmx = mx;

            for (int c = li; c <= ri; ++c) {
                int cur = mx;
                while (cur < n && s[cur] != c) {
                    cur++;
                }
                nmx = max(nmx, cur);
            }
            mx = nmx + 1;
        }

        if (mx > n) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
