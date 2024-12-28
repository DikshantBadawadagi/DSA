#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    int mini=INT_MAX,maxi=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mini=min(mini,a[i]);
        maxi=max(maxi,a[i]);
    }
    vector<int>b(m);
    int mini1=INT_MAX;
    for(int i=0;i<m;i++){
        cin>>b[i];
        mini1=min(mini1,b[i]);
    }

    if(max(2*mini,maxi) < mini1){
        cout<<max(2*mini,maxi)<<endl;
    }
    else{
        cout<<-1<<endl;
    }


}