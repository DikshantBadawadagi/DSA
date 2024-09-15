#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls,int i, int cows){
    int lastCow = stalls[0],ncows =1;
    int n = stalls.size();
    for(int j=1;j<n;j++){
        if(stalls[j] - lastCow >= i){
            ncows++;
            lastCow = stalls[j];
          if(ncows >= cows){return true;}
        }
    }
    return false;
}
int main(){
    vector<int>stalls = {0,3,4,7,10,9};
    sort(stalls.begin(),stalls.end());
    int cows = 4;
    int n = stalls.size();
    int low = 1;
    int high = stalls[n-1] - stalls[0];
    while(low <= high){
        int mid = (low+high)/2;
        if(isPossible(stalls,mid,cows) == true){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    cout<<high;
}