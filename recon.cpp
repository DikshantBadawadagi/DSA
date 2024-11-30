#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int min=INT_MAX,l,r;
    for(int i=0;i<n;i++){
        if(abs(a[i] - a[(i+1)%n]) < min){
            min = abs(a[i] - a[(i+1)%n]);
            l = i;
            r = (i+1)%n;
        }
    }
    cout<<l +1<<" "<<r+1<<endl;
}