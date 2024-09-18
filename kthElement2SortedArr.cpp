#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n1 = a.size();
        int n2 = b.size();
        if(n1>n2) return kthElement(b,a,k);

        int low = 0,high= min(n1,k);
        int left =k;

        while(low<=high){
            int mid = (low+high) >> 1;
            int l1 = INT_MIN, l2 = INT_MIN,r1 = INT_MAX,r2 =INT_MAX;
            if(mid > 0)l1 = a[mid-1];
            if(mid < n1)r1 = a[mid];
            if(mid > 0)l2 = b[k-mid-1];
            if(mid < n2)r2 = b[k-mid];

            if(l1 <= r2 && l2 <= r1){
                return max(l1,l2);
            } 

            else if(l1 > r2){
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return -1;
        // code here
    }
int main() {
    vector<int>a = {5 ,5, 8, 8, 8, 9, 11, 11, 11, 11, 11};
    vector<int>b = {4, 4, 4 ,4 ,6 ,8 ,9 ,9 ,9 ,11, 13};
    int k=2;
    // cin>>k;
    int ans = kthElement(a,b,k);
    cout<<ans<<endl;
}