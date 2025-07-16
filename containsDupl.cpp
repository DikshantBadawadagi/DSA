#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ordered_set<int>os;
    int l=0,r=0;
    vector<int> nums = {1,2,3,1};
    int k = 3;
    int valDiff = 0;
    int n = nums.size();
    while(r < n){
        if(r- l > k){
            os.erase(os.find(nums[l])); 
            l++;
        }
        int lb = nums[r] - valDiff;
        int ub = nums[r] + valDiff;
        int count = os.order_of_key(ub + 1) - os.order_of_key(lb);
        if(count > 0){
            cout<<"true"<<endl;
            return 0;
        }
        os.insert(nums[r]);
        
        r++;
    }
    cout<<"false"<<endl;
}