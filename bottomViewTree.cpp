#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data): data(data), left(nullptr),right(nullptr){
    }
};

void bottom(Node* root,map<int,int>& mpp, queue<pair<Node*,int>>& q){

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int line = it.second;
        mpp[line] = node->data;

        if(node->left!=nullptr){
            q.push({node->left,line-1});
        }
        if(node->right!=nullptr){
            q.push({node->right,line+1});
        }
    }
  

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

    map<int,int> mpp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    bottom(root,mpp,q);
    for(auto it: mpp){
        cout<<it.second<<" ";
    }
}