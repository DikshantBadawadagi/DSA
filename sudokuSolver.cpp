#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isValid(char c,int i, int j,vector<vector<char>>&board){
    for(int x = 0;x<9;x++){
        if(board[i][x] == c) return false;

        if(board[x][j] == c)return false;

        if(board[3*(i/3)+ x/3][3*(j/3) + x%3] == c)return false;

    }
        return true;
}
bool solveSudoku(vector<vector<char>>&board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j] == '.'){
                for(char c='1';c<='9';c++){
                    if(isValid(c,i,j,board)){
                        board[i][j] = c;
                        if(solveSudoku(board))return true;
                        
                        else board[i][j] = '.';
                        
                    }
                }
                    return false;
            }
        }

    }
    return true;
}
int main(){
     vector<vector<char>>board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };

    solveSudoku(board);

      for(int i= 0; i< 9; i++){
        for(int j= 0; j< 9; j++)
            cout<<board[i][j]<<" ";
            cout<<"\n";
    }
    return 0;
}