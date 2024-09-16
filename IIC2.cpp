#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n,m;
        cin >> n >> m;
        int sum=0;
        int k=n*2 -2;
        int m1 =m;
        for(int i=0;i<k;i++){
            m=m+1;
            sum+=m;
        }
        cout<<m1*(m1+1) + sum <<endl;
        
    }
}