#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int f(int ind,int x, vector<int>&val){
    if(ind==0){
        if(x%val[0] == 0) return 1;
        return 0;
    }
    if(x==0) return 1;

    int nottake = f(ind-1,x,val)%mod;
    int take = 0;

    if(val[ind]<=x){
        take = f(ind-1,x-val[ind],val)%mod;
    }

    return (take+nottake)%mod;
}

int main () {
    int n;
    cin>>n;

    int x;
    cin>>x;

    vector<int>val(n);

    for(int i=0;i<n;i++){
        cin>>val[i];
    }

    cout<<f(n-1,x,val)%mod<<endl;

}