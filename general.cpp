#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>num(n);
    for(int i=0;i<n;i++) cin>>num[i];
    vector<int> temp = num;
    sort(temp.begin(),temp.end());
    int mini = temp[0];
    int maxi = temp[n-1];
    int l = 0;
    int r = n-1;
    int a,b;
    bool f=true;
    bool f1=true;
    for(int i=0;i<n;i++){
        if(num[l] == maxi && f==true){
            a = l;
            f=false;
        }
        else l++;
        if(num[r]==mini && f1==true){
            b = r;
            f1=false;
        }
        else r--;
    }
    if(l>r){
            cout<<a+n-2-b;
    }
    else{
    cout<<a+n-1-b;
    }

}