#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main() {
    vector<int>nums = {5,2,6,1};
    int n = nums.size();
    ordered_set<int>os;
    vector<int>ans;
    for(auto num : nums)os.insert(num);
    for(int i=0;i<n;i++){
        ans.push_back(os.order_of_key(nums[i]));
        os.erase(nums[i]);
    }
    for(auto num : ans)cout<<num<<" ";
}