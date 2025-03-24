#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> segs(n); // (l, r, idx)
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segs[i] = {l, r, i + 1}; // 1-based indices
    }

    // Sort: l asc, r desc
    sort(segs.begin(), segs.end(), [](auto a, auto b) {
        if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
        return get<1>(a) > get<1>(b);
    });

    int max_r = -1, j = -1;
    for (int i = 0; i < n; i++) {
        int l = get<0>(segs[i]);
        int r = get<1>(segs[i]);
        int idx = get<2>(segs[i]);
        
        if (max_r >= r && j != -1) { // Found an inner segment
            cout << idx << " " << j << endl;
            return 0;
        }
        if (r > max_r) {
            max_r = r;
            j = idx;
        }
    }
    cout << "-1 -1" << endl;
    return 0;
}