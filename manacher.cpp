#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    string ss = "#";
    for(int i=0;i<s.length();i++){
        ss+=s[i];
        ss+='#';
    }
    // cout<<ss<<endl;
    int n=  ss.length();
    vector<int>p(n+1,0);
    int left =0,right=0;

    for(int i=0;i<n;i++){
        if(i < right){
            p[i] = min(p[left + right - i],right - i);
        }
        while(i - p[i] - 1 >= 0 && i + p[i] + 1 < n && ss[i - p[i] - 1] == ss[i + p[i] + 1]){
            p[i]++;
        }
        if(i + p[i] > right){
            left = i - p[i];
            right = i + p[i];
        }
    }
    for(int i=1;i<n;i+=2){
        cout<<p[i] -1<<" ";
    }
//     int max_len = 0;
// int center_index = 0;

// for(int i = 0; i < n; i++){
//     if(p[i] > max_len){
//         max_len = p[i];
//         center_index = i;
//     }
// }

// int start = center_index - p[center_index] + 1;
// int end = center_index + p[center_index] - 1;

// string longest_palindrome = "";
// for(int i = start; i <= end; i++){
//     if(ss[i] != '#'){
//         longest_palindrome += ss[i];
//     }
// }

// cout << longest_palindrome << endl;

}