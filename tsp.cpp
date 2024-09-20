#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define n 5

int mat[n][n] = {
        {999, 20, 30, 10, 11},
        {15, 999, 16, 4, 2},
        {3, 5, 999, 2, 4},
        {19, 16, 18, 999, 3},
        {16, 4 ,7, 16, 999}
    };

int Subtract_r(){
    int sum=0, min;
    for(int i=0;i<n;i++){
             if(mat[i][0]!=999){
             min = mat[i][0];
             }
          
        for(int j=0;j<n;j++){
            if(mat[i][j]!=-1){
               if(mat[i][j]<min){
                min = mat[i][j];
              }
            }
        }
        sum +=min;
        if(min!=0){   
        for(int j=0;j<n && mat[i][j]!=-1 ;j++){
        mat[i][j] = mat[i][j]-min;
        }
        }
       
    }
      return sum;
}

int Subtract_c(){
    int sum=0,min;
    for(int i=0;i<n;i++){
       if(mat[0][i]!=-1){
             min = mat[0][i];
             }
              for(int j=0;j<n;j++){
            if(mat[j][i]!=-1){
               if(mat[j][i]<min){
                min = mat[j][i];
              }
            }
        }
                sum +=min;
        if(min!=0){
            for(int j=0;j<n && mat[i][j]!=-1 ;j++){
                mat[j][i] = mat[j][i]-min;
            }
        }
    }
    return sum;  
}

int main() {
int sum = Subtract_r() + Subtract_c();
cout<<sum;
    
  return 0;
 }
