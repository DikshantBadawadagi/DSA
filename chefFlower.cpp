#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numberOfTests;
    cin >> numberOfTests;
    while (numberOfTests--) {
        int flowerCount, minimumBloom, dayCount;
        cin >> flowerCount >> minimumBloom >> dayCount;
        vector<int> regrowthPeriods(flowerCount);
        for (int i = 0; i < flowerCount; i++) {
            cin >> regrowthPeriods[i];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> regrowthCalendar;
        vector<bool> isPlucked(flowerCount, false);
        int totalPlucks = 0;
        int bloomingCount = flowerCount;

        for (int currentDay = 1; currentDay <= dayCount; currentDay++) {
            // Reintroduce regrown flowers
            while (!regrowthCalendar.empty() && regrowthCalendar.top().first <= currentDay) {
                int flowerId = regrowthCalendar.top().second;
                regrowthCalendar.pop();
                if (isPlucked[flowerId]) {
                    bloomingCount++;
                    isPlucked[flowerId] = false;
                }
            }

            // Greedily pluck as many flowers as possible
            while (true) {
                int bestFlower = -1, minRegrowth = INT_MAX;
                for (int i = 0; i < flowerCount; i++) {
                    if (!isPlucked[i] && regrowthPeriods[i] < minRegrowth) {
                        minRegrowth = regrowthPeriods[i];
                        bestFlower = i;
                    }
                }
                if (bestFlower == -1 || bloomingCount - 1 < minimumBloom) break;
                regrowthCalendar.emplace(currentDay + regrowthPeriods[bestFlower], bestFlower);
                isPlucked[bestFlower] = true;
                bloomingCount--;
                totalPlucks++;
            }
        }

        cout << totalPlucks << endl;
    }
    return 0;
}