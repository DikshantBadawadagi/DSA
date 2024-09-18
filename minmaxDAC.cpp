#include<iostream>
#include<bits/stdc++.h>
using namespace std;

pair<int,int> minmax(int i, int j, vector<int>&v){
int mid;
    if(i==j){
      return  make_pair(v[i],v[i]); 
       
    }
    if(i == j-1){
       return make_pair(min(v[i], v[j]), max(v[i], v[j]));
    }
    else {
        mid =(i +j)/2;
        pair<int,int>left = minmax(i,mid,v);
        pair<int,int>right = minmax(mid+1,j,v);
       return make_pair(min(left.first, right.first), max(left.second, right.second));
    }

     
  }

int main() {
    vector<int>v = {1,2,3,4,5,6,7};
   int  n = v.size();
   int i=0,j=n-1;
    pair<int, int> result = minmax(i, j, v);
    cout << "Minimum: " << result.first << endl;
    cout << "Maximum: " << result.second << endl;
return 0;
}

