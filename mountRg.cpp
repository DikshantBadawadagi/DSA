#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    int l=0,r=1,ans=0,cnt=0;

    while( r < n){
        if(a[r] < a[l]){
            cnt++;
            r++;
        }
        else{
            ans = max(cnt, ans);
            l = r;
            r = l + 1;
            cnt = 0;
        }
    }
    ans = max(cnt, ans);
    cout<<ans+1<<endl; 
}