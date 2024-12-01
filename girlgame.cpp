#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int n = s.length();
  int count = 0;
  map<char,int>mpp;
  for(char c : s) {
    mpp[c]++;
  }
  for(auto it : mpp) {
    if(it.second&1){
        count++;
    }
  }
  
  if(count&1 || count == 0){
    cout<<"First"<<endl;
  }
  else{
    cout<<"Second"<<endl;
  }

}