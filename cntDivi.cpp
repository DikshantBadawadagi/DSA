#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
vector<int> divisors(MAX, 0);

void precompute() {
    for (int i = 1; i < MAX; i++) {
        for (int j = i; j < MAX; j += i) {
            divisors[j]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    precompute(); // O(N log N)

    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        cout << divisors[a] << "\n";
    }
}
