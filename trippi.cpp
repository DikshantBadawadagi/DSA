#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        string a,b,c;
        cin>>a>>b>>c;
        string ans="";
        ans += a[0];ans+=  b[0]; ans+=  c[0];
        cout<<ans<<endl;
    }
}