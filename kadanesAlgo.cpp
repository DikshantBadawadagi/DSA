#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxi = INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>maxi){
            maxi = sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    cout<<maxi<<endl;
}