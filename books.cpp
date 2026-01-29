#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int t;
    cin>>n>>t;
    vector<int>a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<long long>pref(n);

    pref[0]=a[0];

    for(int i=1;i<n;i++){
        pref[i]=pref[i-1]+a[i];
    }

    int ans =0;

    for(int i=0;i<n;i++){
        int ub = t + (i>0 ? pref[i-1] : 0);
        int idx = upper_bound(pref.begin(), pref.end(), ub) - pref.begin();
        ans = max(ans, idx - i);
    }
    cout<<ans<<endl;
}
