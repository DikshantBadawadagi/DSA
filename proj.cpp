#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Project {
    ll start, end, reward;
};

bool compare(Project &a, Project &b) {
    return a.end < b.end; // sort by ending time
}

int main() {
    int n;
    cin >> n;
    vector<Project> projects(n);
    for (int i = 0; i < n; i++) {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }

    sort(projects.begin(), projects.end(), compare);

    // End times for binary search
    vector<ll> endTimes;
    for (auto &p : projects) endTimes.push_back(p.end);

    // DP array
    vector<ll> dp(n);
    for (int i = 0; i < n; i++) {
        // Include current project
        ll include = projects[i].reward;

        // Find last project that ends before current starts
        int l = upper_bound(endTimes.begin(), endTimes.end(), projects[i].start - 1) - endTimes.begin() - 1;
        if (l >= 0) include += dp[l];

        // Exclude current project
        ll exclude = (i > 0) ? dp[i - 1] : 0;

        dp[i] = max(include, exclude);
    }

    cout << dp[n - 1] << endl;
}
