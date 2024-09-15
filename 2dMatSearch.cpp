#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> mat = {{1, 2, 3, 4}, 
                                  {5, 6, 7, 8}, 
                                  {9, 10, 11, 12}}; 
    int target = 8;
    int n = mat.size();
    int low=0,high=n-1,mid;
    int row=-1;
    for(int i=1;i<n;i++){
        if(target <mat[i][0]){
            row = i-1;
            break;
        }
    }
    if(row == -1) {
        row = n - 1;
    }


    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        if (mat[row][mid] == target)
            return mid;

        // If x greater, ignore left half
        if (mat[row][mid] < target)
            low = mid + 1;

        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }

    cout<<"NO";
    
}