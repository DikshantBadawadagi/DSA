#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n,r,avg;
    cin >> n >> r >> avg;

    vector<pair<long long,long long>> a(n);
    long long total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;
        total += a[i].second;
    }
    sort(a.begin(), a.end());
    long long avg_needed = avg * n - total;

    long long ans = 0;
    for (int i = 0; i < n && avg_needed > 0; i++) {
        long long can_add = min(avg_needed, r - a[i].second);
        ans += can_add * a[i].first;
        avg_needed -= can_add;
    }

    cout << ans << endl;
    return 0;
        
}