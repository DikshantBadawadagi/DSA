#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
vector<int>w(n);
int cnt1 =0,cnt2=0;
for(int i=0;i<n;i++){
    cin>>w[i];
    if(w[i] == 100)cnt1++;
    else cnt2++;
}
// cout<<cnt1<<" "<<cnt2<<endl;
// if(cnt1 == 0){
//     if(cnt2%2 == 0)cout<<"YES"<<endl;
// }
// else if(cnt2 == 0){
//     if(cnt1%2 == 0)cout<<"YES"<<endl;
// }
// else if(cnt2*2 == cnt1 )cout<<"YES"<<endl;
// else cout<<"NO"<<endl;
        long long baki_200=cnt2%2;
        long long baki_100=cnt1-(baki_200*2);

        if(baki_100>=0 && baki_100%2==0)
            cout<<"YES";
        else
            cout<<"NO";


}