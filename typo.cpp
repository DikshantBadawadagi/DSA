#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    string ans = "";

    for (char c : s) {
        int n = ans.size();

        if (n >= 2 && ans[n - 1] == c && ans[n - 2] == c) {
            continue;
        }

        if (n >= 3 && ans[n - 1] == c && ans[n - 2] == ans[n - 3]) {
            continue;
        }

        ans += c;
    }

    cout << ans << endl;
    return 0;
}