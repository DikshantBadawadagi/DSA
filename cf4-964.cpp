#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        long long n1,n2;
        cin>>n1>>n2;
        long long num2 = n1+1,num3 = n1 +2;
        int sum=0;
        while(n1!=0){
            num2 = num2*3;
            n1 = n1/3;
            sum++;
        }
        while(num2!=0){
            num2 = num2/3;
            sum++;
        }
     n2 = n2-3;
        for(int i=num3;i<=n2;i+=3){
            long long number = i;
            int count=0;
            while(number!=0){
                number = number/3;
                count++;
            }
            sum = sum + 3*count;
        }
        cout<<sum<<endl;
    }
}