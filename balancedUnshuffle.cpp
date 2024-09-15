#include <bits/stdc++.h> 
using namespace std; 


int main() {
    string s1;
    cin>> s1;
 vector<tuple<int ,int , char>>v1;
 long long i,j,k,a,b,count=0;

for(i=0;i<s1.length();i++){

v1.push_back({count,-i,s1[i]});
if(s1[i] == '('){
    count++;
}
else if(s1[i]==')'){
    count--;
}
}

sort(v1.begin(),v1.end());

for(j=0;j<s1.length();j++){
    cout<< get<2>(v1[j]);
}
return 0;
}