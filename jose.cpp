#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> circle;
    for (int i = 1; i <= n; ++i) {
        circle.insert(i);
    }

    auto it = circle.begin();
    vector<int> result;

    while (!circle.empty()) {
        // Move one step ahead (second child)
        it++;
        if (it == circle.end()) it = circle.begin();  // Wrap around

        result.push_back(*it);
        auto to_erase = it++;

        if (it == circle.end()) it = circle.begin();

        circle.erase(to_erase);
    }

    for (int x : result) cout << x << " ";
    cout << endl;
}
