#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    bool found = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == x) found = true;
    }

    int added = 0;
    if (!found) {
        a.push_back(x);
        added++;
    }

    while (true) {
        sort(a.begin(), a.end());
        int current_n = a.size();
        int median_pos = (current_n + 1) / 2 - 1; 

        if (a[median_pos] == x) break;

        if (a[median_pos] < x) {
            a.push_back(100000);
        } else {
            a.push_back(1);     
        }
        added++;
    }

    cout << added << endl;
    return 0;
}