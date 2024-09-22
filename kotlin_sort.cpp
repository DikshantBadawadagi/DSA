#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        long long x,y;
        cin>>x>>y;
        cout<<min(x,y)<<max(x,y)<<endl;
    }
}