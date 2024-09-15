#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long>num(n);
        long long maxi_odd=LONG_LONG_MIN,maxi_even=LONG_LONG_MIN;
        for(int i=0;i<n;i++){
            cin >> num[i];
            if(num[i]%2 == 1){
            maxi_odd = max(maxi_odd,num[i]);}
            else{
                maxi_even = max(maxi_even,num[i]);}
            }
        if(maxi_odd == LONG_LONG_MIN || maxi_even == LONG_LONG_MIN){
            cout<<0<<endl;
            continue;
        }
        int count=0;
        sort(num.begin(),num.end());
        for(int i=0;i<n;i++){
            if(num[i]%2 == 0 ){
                if(num[i] < maxi_odd){
                num[i] = num[i] +maxi_odd;
                    maxi_odd = min(num[i],maxi_odd ); 
                count++;}

                else if(num[i] > maxi_odd){
                    while(maxi_odd <= num[i]){
                        long long temp;
                       temp = min(maxi_odd,num[i]) ;
                       if(temp == maxi_odd){
                        maxi_odd = maxi_odd + num[i];
                       }
                       else{
                        num[i] = maxi_odd + num[i];
                       }
                    count++;
                }
                }

            
           
        }
        }
        cout<<count<<endl;






        }
    }
