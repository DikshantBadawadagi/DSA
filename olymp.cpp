#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long f(long long n,long long l,long long r,long long x,vector<long long> &a,long long sum,long long i,long long len,long long mini,long long maxi){
    
    if(i == n){
        if(sum >= l && sum <= r && len >= 2 && mini != 1e9 && maxi != -1e9 && (maxi - mini) >= x){
            return 1;
        }
        return 0;
    }

    //pick
    long long pick = f(n, l, r, x, a, sum + a[i], i + 1, len + 1, min(mini, a[i]), max(maxi, a[i]));

    //notPick
    long long notPick = f(n, l, r, x, a, sum, i + 1, len, mini, maxi);

    return pick + notPick;
}

int main(){
    long long n,l,r,x;
    cin>>n>>l>>r>>x;

    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<f(n,l,r,x,a,0,0,0,1e9,-1e9)<<endl;
}