#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        vector<pair<int,int>> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i].second >> nums[i].first; 
        }

        sort(nums.begin(), nums.end()); 

        long long ans = 0;
        ordered_set st;

        for(auto & num : nums){
            ans += st.size() - st.order_of_key(num.second);
            st.insert(num.second);
        }

        cout << ans << "\n";
    }

    return 0;
}
