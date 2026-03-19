#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve() {
    long long n;
    cin >> n;

    if (n == 1) {
        cout << "FastestFinger" << endl;
        return;
    }
    if (n % 2 != 0 || n == 2) {
        cout << "Ashishgup" << endl;
        return;
    }

    if ((n & (n - 1)) == 0) {
        cout << "FastestFinger" << endl;
        return;
    }

    if (n % 2 == 0 && (n / 2) % 2 != 0) {
        if (is_prime(n / 2)) {
            cout << "FastestFinger" << endl;
        } else {
            cout << "Ashishgup" << endl;
        }
        return;
    }

    cout << "Ashishgup" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}