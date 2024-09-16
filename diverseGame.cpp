#include<iostream>
#include<bits/stdc++.h>
using namespace std;



vector<vector<int>> rotateMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    // Create a new matrix to store the result
    vector<vector<int>> rotatedMatrix(n, vector<int>(m));
    
    // Rotate the rows
    for(int i = 0; i < n; ++i) {
        int newRowIndex = (i + 1) % n;
        rotatedMatrix[i] = matrix[newRowIndex];
    }
    
    return rotatedMatrix;
}

vector<vector<int>> rotateRows(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    // Create a new matrix to store the result
    vector<vector<int>> rotatedMatrix(n, vector<int>(m));
    
    // Rotate each row
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            rotatedMatrix[i][j] = matrix[i][(j + 1) % m];
        }
    }
    
    return rotatedMatrix;
}


int main(){

    long long t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;   
        vector<vector<int>> matrix(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>matrix[i][j];
            }
        }
        if(n==1 && m==1){
            cout<<-1<<endl;
        }
        else{
        vector<vector<int>> rotatedMatrix = rotateMatrix(matrix);
        vector<vector<int>>ans = rotateRows(rotatedMatrix);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        }
         


    }
}