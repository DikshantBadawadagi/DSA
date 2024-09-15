
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
        int n,result=0,max=0;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n-1;i++){
            if(max<a[i]){
                max=a[i];
            }
        }
        result = a[n-1] + max;
        cout<<result<<endl;
    }

}