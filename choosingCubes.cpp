#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        int n,f,k,temp;
        cin>>n>>f>>k;
        int a[n];

        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        temp = a[f];
        sort(a,a+n,greater<int>());
         bool foundMaybe = false;
        bool foundYes = false;
        for(int i=0;i<k;i++){
            if(a[i] == temp){
                for(int j=i+1;j<n && a[j]<=temp;j++){
                    if(a[j] == temp && j>k){
                        foundMaybe = true;
                        break; 
                    }
                }
                foundYes = true;
            }
        }
         if (foundMaybe) {
            cout << "maybe" << endl;
        } else if (foundYes) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}