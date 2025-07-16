// Om namah shivaya
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto&j : a) cin >> j;

    //Previous biggest
    vector<int> prevBig(n, -1);
    for(int i = 0; i < n; i++){
        int k = i - 1;
        while(k >= 0 && a[k] < a[i]){
            k = prevBig[k];
        }
        prevBig[i] = k;
    }

    //score calc
    ordered_set<int> indices;
    set<array<int, 2>> nums;
    int score = 0;
    for(int i = 0; i < n; i++){
        // condition 1: left boundary should be bigger, all these numbers would be stored in nums and indices
        // condition 2: current number is right boundary, so all indices must be bigger than the prevbig
        int lb = prevBig[i]; //gteq lb
        int rb = i - 2; //lteq i - 2, so that size is atleast 3
        
        // to find how many lie between lb and rb, we can find how many 
        // are less then lb and greater than rb and subtract them from the size
        int numltlb = indices.order_of_key(*indices.lower_bound(lb));
        int numgtrb = indices.size() - indices.order_of_key(*indices.upper_bound(rb));
        score += max(0ull, indices.size() - numltlb - numgtrb);
        
        // Now to maintain that in both our sets only valid right bounds 
        // are there we will remove the numbers smaller than or equal to a[i]
        while(!nums.empty() && (*nums.begin())[0] <= a[i]){
            indices.erase((*nums.begin())[1]);
            nums.erase(nums.begin());
        }
        nums.insert({a[i], i});
        indices.insert(i);
    }
    cout << score << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}