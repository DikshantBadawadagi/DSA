#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr = {-1,0,1,0};
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i=0;i<arr.size();i++){
        if (i != 0 && arr[i] == arr[i - 1]) continue;
        int j =i+1;
        int k = arr.size()-1;
        while(k>j){
            int sum = arr[i]+arr[j]+arr[k];
            if(sum > 0){
                k--;
            }
            else if(sum < 0){
                j++;
            }
            else{
                vector<int>temp = {arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                 while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }

    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }

}






  