#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int func(int n,int m,int mid){
    long long ans = 1;
    for(int i = 1;i <= n;i++){
        ans = ans*mid;
        if(ans > m )return 2;
    }
    if(ans < m)return 1;
     return 0;
}
int NthRoot(int n,int m){
    int low = 1, high = m;
    while(low <= high){
        int mid = (low + high) / 2;
        int midN = func(n,m,mid) ;
        if(midN == 0){
            return mid;
        }
        else if(midN ==2){
            high = mid-1;
        }
        else if(midN == 1){
            low = mid+1;
        }
    }
    return -1;
}
int main() {
    int n,m;
    cin>>n>>m;
    int ans = NthRoot(n,m);   
    cout<<ans;

    return 0;
}