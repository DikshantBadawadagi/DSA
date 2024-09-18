#include<bits/stdc++.h>
using namespace std;

int main () {
    
    vector<int>v = {11,33,33,11,33,11};
    v.p
    int n = v.size();

    //declaring a map:
    map<int, int> mpp;

    //storing the elements with its occurnce:
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;
    }

    //searching for the majority element:
    for (auto it : mpp) {
        if (it.second > (n / 3)) {
            cout<<it.first;
        }
    }

}