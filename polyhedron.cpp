#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<string>inp(n);
    for(int i=0;i<n;i++) cin>>inp[i];
    int sum=0;
  for(string a : inp){
    if(a == "Icosahedron"){
        sum+=20;
    }
    else if(a == "Cube"){
        sum+=6;
    }
    else if(a=="Tetrahedron"){
        sum+=4;
    }
    else if(a=="Octahedron"){
        sum+=8;
    }
    else{
        sum+=12;
    }
  }
  cout<<sum;

}