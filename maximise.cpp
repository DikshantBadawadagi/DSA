#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

int min(int a,int b){
    if(a>b){return b;}
    return a;
}

int main() {
long long t;
cin>>t;
for(long long i=0;i<t;i++){    
long long a[100], minimum=0,n;
   cin>>n;
   for(long long i=0;i<2*n;i++){
    cin>>a[i];
   }
   sort(a,a+2*n);
for(long long i=0;i<n;i++){
     minimum = minimum+min(a[2*i],a[2*i+1]);
    //cout << minimum << endl;
}
cout << minimum << endl;
}
return 0;
}