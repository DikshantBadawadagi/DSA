#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    int j=0,maxi=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
       
        if(ceil(double(a[i])/m)>=maxi){
            maxi=ceil(double(a[i])/m);
            j=i;
        }
    }
    cout<<j+1<<endl;
    

}