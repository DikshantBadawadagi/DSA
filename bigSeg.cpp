#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool comp(const pair<int, int>& num1, const pair<int, int>& num2){
    if(num1.first==num2.first){
        return num1.second>num2.second;
    }
    return num1.first<num2.first;
}
int main() {
    long long n;
    cin>>n;
    vector<pair<int,int>>v(n);
    vector<pair<int,int>>u(n);
    for(int i=0;i<n;i++){
      cin>>v[i].first>>v[i].second;
      u[i]=v[i];
    }
    sort(v.begin(),v.end(),comp);
    int min = v[0].first;
    int max = v[0].second;
    int ans;
    for(int i=0;i<n;i++){
        if(u[i].first == min && u[i].second == max){
            ans = i;
        }
        else if(u[i].first < min || u[i].second > max){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ans+1<<endl;
    return 0;

}