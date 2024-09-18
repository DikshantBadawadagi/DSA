#include<iostream>
#include<bits/stdc++.h>
using namespace std;


double getMedian(vector<int>a,vector<int>b){
    int n1=a.size();
    int n2=b.size();
    if(n1>n2) getMedian(b,a);
    int low=0,high = n1;
    int left = (n1 + n2 +1)/2;
    int n = n1+n2;
    while(low<=high){
        int mid1 = (low + high) >> 1,mid2 =left - mid1;
        int l1 = INT_MIN,r1 = INT_MAX ,l2=INT_MIN,r2=INT_MAX;
        if(mid1 < n1) r1 = a[mid1];
        if(mid2 < n2) r2 = b[mid2];
        if(mid1 -1 >= 0) l1 = a[mid1-1];
        if(mid2 -1 >=0) l2 = b[mid2-1];

        if(l1 <= r2 && l2 <= r1){
            if((n+1)%2 == 0) return (max(l1,l2));
             else{
                return (double)((max(l1,l2) + min(r1,r2))/2.0);
             }
        }

        else if(l1 > r2){
            high = mid1 - 1;
        }
        else if(l2 > r1){
            low = mid1 + 1; 
        }
    }
    return 0;
}
int main() {
    vector<int>a = {2,4,6,8};
    vector<int>b = {1,3,5,7,9,11};

    int ans = getMedian(a,b);
    cout<<ans<<endl;
}
