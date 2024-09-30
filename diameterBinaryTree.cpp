#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data):data(data),left(nullptr),right(nullptr){}
};
int leftHeight(Node* root){
    if(root == nullptr){
        return 0;
    }
    int lh = leftHeight(root->left);
    int rh = leftHeight(root->right);

   return 1 + max(lh,rh);
}
int rightHeight(Node* root){
    if(root == nullptr){
        return 0;
    }
    int rh = rightHeight(root->right);
    int lh = rightHeight(root->left);

    return 1+ max(rh,lh);
}

int main(){
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

    int lh = leftHeight(root);
    int rh= rightHeight(root);
    
    cout<<1 + lh + rh;
}
