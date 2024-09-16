#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin>>n;
       vector<string> vec;
       vec.reserve(n);
       for(int i=0;i<n;i++){
        string s;
        cin>>s;
vec.push_back(s);
       }

    unordered_map<string, int> freqMap;

    for (const auto& str : vec) {
        freqMap[str]++;
    }

    string maxString;
    int maxCount = 0;

    for (const auto& pair : freqMap) {
        if (pair.second > maxCount) {
            maxString = pair.first;
            maxCount = pair.second;
        }
    }
 int mid = n/2;
    if(maxCount == 1 || maxCount<mid){
        cout<<"uh-oh";
        return 0;
    }
    cout<<maxString;
}