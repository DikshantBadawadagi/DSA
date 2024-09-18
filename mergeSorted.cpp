#include<bits/stdc++.h>
using namespace std;

int main() {
 long long arr1[] = {1,2,3,0,0,0};
 long long arr2[] = {2,5,6};
 int n = 3, m = 3;
 int p=n-1,q=0;
 while(p>=0 && q<m){
    if(arr1[p]>arr2[q]){
        swap(arr1[p],arr2[q]);
        p--;q++;
    }
    else{
        break;
    }
 }
 sort(arr1,arr1+n);
 sort(arr2,arr2+m);
 for(int i=0;i<n;i++){
    cout<<arr1[i];
 }

 for(int i=0;i<m;i++){
    cout<<arr2[i];
 }

}
