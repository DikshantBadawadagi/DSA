#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second; // Input x and y coordinates
    }

    int supercentral_count = 0;

    for (int i = 0; i < n; i++) {
        bool has_left = false, has_right = false, has_upper = false, has_lower = false;

        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            if (points[j].first < points[i].first && points[j].second == points[i].second) {
                has_left = true; // Left neighbor
            }
            if (points[j].first > points[i].first && points[j].second == points[i].second) {
                has_right = true; // Right neighbor
            }
            if (points[j].first == points[i].first && points[j].second > points[i].second) {
                has_upper = true; // Upper neighbor
            }
            if (points[j].first == points[i].first && points[j].second < points[i].second) {
                has_lower = true; // Lower neighbor
            }
        }

        if (has_left && has_right && has_upper && has_lower) {
            supercentral_count++; // Point is supercentral
        }
    }

    cout << supercentral_count << endl;
    return 0;
}
