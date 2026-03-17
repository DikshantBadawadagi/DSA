#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<long long> a(3);
    for(int i=0;i<3;i++) cin >> a[i];

    long long maxi =0;

    for(int m = 0;m<=2;m++){
        long long sum =0;
        if (a[0] >= m && a[1] >= m && a[2] >= m){
        if(a[0] >= m) sum+= (a[0] - m)/3;
        if(a[1] >= m) sum+= (a[1] - m)/3;
        if(a[2] >= m) sum+= (a[2] - m)/3;
        maxi = max(maxi,sum + m);}
    }
    cout << maxi << endl;
    return 0;
    
}