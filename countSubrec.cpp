#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);

    vector<long long> cntA(n + 1, 0);
    int len = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) len++;
        else {
            if (len > 0) {
                for (int j = 1; j <= len; j++)
                    cntA[j] += len - j + 1;
                len = 0;
            }
        }
    }
    if (len > 0)
        for (int j = 1; j <= len; j++)
            cntA[j] += len - j + 1;

    vector<long long> cntB(m + 1, 0);
    len = 0;
    for (int i = 0; i < m; i++) {
        if (b[i] == 1) len++;
        else {
            if (len > 0) {
                for (int j = 1; j <= len; j++)
                    cntB[j] += len - j + 1;
                len = 0;
            }
        }
    }
    if (len > 0)
        for (int j = 1; j <= len; j++)
            cntB[j] += len - j + 1;

    long long ans = 0;
    for (int h = 1; h <= n && h <= k; h++) {
        if (k % h == 0) {
            int w = k / h;
            if (w <= m) ans += cntA[h] * cntB[w];
        }
    }
    printf("%lld\n", ans);
    return 0;
}