#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n,k;
    cin >> n >> k;
    long long x,a,b,c;
    cin>>x>>a>>b>>c;

    //ax + b %c
    long long sum = 0;
    long long prev = x;
    sum += prev;
    if(k == n){
        for(long long i=1;i<n;i++){
            prev = (a * prev + b) % c;
            sum += prev;
        }
        cout<< sum << endl;
        return 0;
    }

    vector<long long>elements;
    elements.push_back(prev);
    long long l = 0, r = 0;

    long long res = -1;

    while(r < n-1){
        r++;
        prev = (a * prev + b) % c;
        elements.push_back(prev);
        sum += prev;

        if(r - l + 1 > k){
            sum -= elements[l];
            l++;
        }

        if(r - l + 1 == k){
            if(res == -1){
                res = sum;
            }else{
                res ^= sum;
            }
        }
    }
    cout<< res << endl;
    return 0;

}