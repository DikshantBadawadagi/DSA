#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
                                    //start,end,height
    vector<vector<int>>buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<vector<int>>res;
    ordered_multiset<int>st;
    st.insert(0);
    vector<vector<int>>ans;//start,height
    for(auto &build : buildings){
        res.push_back({build[0],-build[2]});
        res.push_back({build[1],build[2]});
    }
    sort(res.begin(),res.end());
    int currMaxi = 0;
    for(auto &p : res){
        if(p[1] < 0){
            st.insert(-p[1]);
        }else{
            st.erase(st.find_by_order(st.order_of_key(p[1])));
        }
        int tempMaxx = *st.rbegin();
        if(tempMaxx != currMaxi){
            ans.push_back({p[0],tempMaxx});
            currMaxi = tempMaxx;
        }
    }
    for(auto &p : ans){
        cout<<p[0]<<" "<<p[1]<<endl;
    }
}