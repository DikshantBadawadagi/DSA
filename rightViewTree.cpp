#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {
    }
};

void right_view(Node* root,int lev,vector<int> &arr){
    if(root == nullptr) return;

    if(lev == arr.size()){
        arr.push_back(root->data);
    }
    right_view(root->right,lev+1,arr);
    right_view(root->left,lev+1,arr);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left =  new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    vector<int>arr;
    right_view(root,0,arr);
    for(auto i:arr){
        cout<<i<<" ";
    }

}