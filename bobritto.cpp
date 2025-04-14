#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m,l,r;
        cin>>n>>m>>l>>r;

        while(l < r){
            if(abs(l) + abs(r) == m){
                cout<<l<<" "<<r<<endl;
                break;
            }
            if(abs(l) + abs(r) > m){
                if(abs(l) > abs(r)){
                    l++;
                }else
                {
                    r--;
                }
            }
        }
    }
}