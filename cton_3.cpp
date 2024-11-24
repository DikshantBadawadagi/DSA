#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        int x, m;
        cin >> x >> m;
        int cnt = 0;

        unordered_map<int, bool> memo;  

        for (int i = 1; i <= m; i++) {
            int num = i ^ x;

            if (x != i && num > 0 && num <= m) { 
                if (memo.find(num) != memo.end()) {
                    if (memo[num]) {
                        cnt++;
                    }
                } else {
                    bool isValid = (x % num == 0 || i % num == 0);
                    memo[num] = isValid;
                    if (isValid) {
                        cnt++;
                    }
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
