#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
vector < vector < int >> arr;
arr = {{1,4},{0,2},{3,5}};
       sort(arr.begin(), arr.end());
       for(int i=0;i<arr.size()-1;i++){
        for(int j=0;j<arr.size()-1;j++){
        if(arr[i+1][0] <= arr[i][1]){
            arr[i][1] = max(arr[i+1][1],arr[i][1]);
            arr.erase(arr.begin() + i + 1);
        }}
       }
       for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
       }
}