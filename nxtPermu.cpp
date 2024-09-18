#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int mini(int num,int i,int n,vector<int> &arr){
    auto start = arr.begin() + i;
    auto end = arr.begin() + n;
    vector<int>new_arr(n-i+1);
    copy(start, end, new_arr.begin());
    sort(new_arr.begin(),new_arr.end());
    for(int j=0;j<(n-i+1);j++){
        if(new_arr[j]>num){
            int temp = arr[i-1];
            arr[i-1] = new_arr[j];
        }

        
    }
}
int main() {
    int n;
    cout<<"Enter the size"<<endl;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=n;i>0;i--){
        if(arr[i-1]<arr[i]){
            arr[i-1]=mini(arr[i-1],i,n,arr);
        }

    }

}