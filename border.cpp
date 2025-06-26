#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i <= r) {
            int k = i - l; // FIXED
            if (z[k] + i <= r) { // Remaining z-box fits
                z[i] = z[k];
            } else {
                l = i;
                while (r < n && s[r] == s[r - l]) r++;
                z[i] = r - l;
                r--;
            }
        } else {
            l = r = i;
            while (r < n && s[r] == s[r - l]) r++;
            z[i] = r - l;
            r--;
        }
    }

    vector<int> ans;
    for (int i = 1; i < n; i++) {
        if (z[i] + i == n) { // FIXED condition
            ans.push_back(z[i]);
        }
    }

    sort(ans.begin(), ans.end());

    if (ans.empty()) {
        cout << "" << endl;
    } else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
