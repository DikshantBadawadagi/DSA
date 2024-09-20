#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int func(vector<int>num,int n){
        int left =1, right =n-2;
        if(n==1) return num[0];
        if(num[0]!=num[1]) return num[0];
        if(num[n-1]!=num[n-2]) return num[n-1];
        while(left<=right){
            int mid = left+(right-left)/2;
        if(num[mid]!=num[mid+1] && num[mid] != num[mid-1]) return num[mid];
            if(mid%2 == 1 && num[mid] == num[mid-1] || mid%2 == 0 && num[mid]== num[mid+1] ){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return -1;
}
int main() {
    vector<int> num = {1,1,2,2,3,3,4,5,5,6,6};
    int n = num.size();
    int ans = func(num,n);
    cout<<ans;
}