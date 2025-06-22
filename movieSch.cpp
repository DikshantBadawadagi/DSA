#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> movies(n);

    for (int i = 0; i < n; i++) {
        cin >> movies[i].second >> movies[i].first; // store as {end, start}
    }

    // Sort movies by end time
    sort(movies.begin(), movies.end());

    multiset<int> endTimes; // end time of last movie watched by each member
    for (int i = 0; i < k; i++) {
        endTimes.insert(0); // all k members are free at time 0
    }

    int count = 0;
    for (auto [end, start] : movies) {
        // Find the member who is free the latest but not after the movie starts
        auto it = endTimes.upper_bound(start);
        if (it == endTimes.begin()) continue; // no one available
        --it;

        endTimes.erase(it);        // assign this movie to the found member
        endTimes.insert(end);      // update their new end time
        count++;
    }

    cout << count << endl;
}
