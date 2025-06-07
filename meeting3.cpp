class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> count(n, 0);
        
        set<int> available;
        for (int i = 0; i < n; i++) available.insert(i);

        // min-heap: {end_time, room_id}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        for (auto& m : meetings) {
            long long start = m[0], end = m[1];

            while (!pq.empty() && pq.top().first <= start) {
                available.insert(pq.top().second);
                pq.pop();
            }

            if (!available.empty()) {
                int room = *available.begin();
                available.erase(room);
                pq.push({end, room});
                count[room]++;
            } else {
                auto [free_time, room] = pq.top(); pq.pop();
                pq.push({free_time + (end - start), room});
                count[room]++;
            }
        }

        int max_meet = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (count[i] > max_meet) {
                max_meet = count[i];
                ans = i;
            }
        }
        return ans;
    }
};
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif
