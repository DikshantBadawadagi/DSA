#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string p, s;
        cin >> p >> s;
        int n = p.length();
        int m = s.length();
        if (m > 2 * n) {
            cout << "NO" << endl;
            continue;
        }
        vector<pair<char, int>> segp, segs;
        char pp = p[0], ps = s[0];
        int cp = 1, cs = 1;

        for (int i = 1; i < n; i++) {
            if (p[i] == pp) cp++;
            else {
                segp.emplace_back(pp, cp);
                pp = p[i];
                cp = 1;
            }
        }
        segp.emplace_back(pp, cp);

        for (int i = 1; i < m; i++) {
            if (s[i] == ps) cs++;
            else {
                segs.emplace_back(ps, cs);
                ps = s[i];
                cs = 1;
            }
        }
        segs.emplace_back(ps, cs);

        int i = 0, j = 0; 
        while (i < segp.size() && j < segs.size()) {
            char a = segp[i].first;
            int l1 = segp[i].second;
            char b = segs[j].first;
            int l2 = segs[j].second;

            if (a != b) {
                cout << "NO" << endl;
                goto brk;
            }

            if (l2 <  l1 || l2 > 2 * l1) {
                cout << "NO" << endl;
                goto brk;
            }
            i++;
            j++;
        }
        if (i == segp.size() && j == segs.size()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
brk:;
    }
    return 0;
}