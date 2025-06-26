#include<iostream>
#include<vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> z(n, 0);
    int l = 0, r = 0;

    // Z-algorithm
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            int k = i - l;
            if (z[k] < r - i + 1) {
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

    vector<int> periods;
    for (int i = 1; i < n; i++) {
        if (z[i] == n - i) { // if the prefix matches the remaining string
            periods.push_back(i);
        }
    }
    periods.push_back(n); // the whole string is always a period

    for (int p : periods) {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}
