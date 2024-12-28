#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n,k;
    cin>>n>>k;
    vector<int>h(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }

long long sum=0,mini=INT_MAX,i=0,j=0,ans;
    while(j<n){
        while(j<n && j-i+1<=k){
        sum+=h[j];
        j++;
        }
        // mini=min(mini,sum);
        if(sum<mini){mini=sum;ans = i+1;};
        sum-=h[i];
        i++;
    }
cout<<ans<<endl;
}