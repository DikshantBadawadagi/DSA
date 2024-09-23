#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
 public:
    int data;
    Node* left;
    Node* right;

    Node(int data):data(data),left(nullptr),right(nullptr){}
};

void vertical(Node* root,map<int,map<int,multiset<int>>>& mpp,queue<pair<Node*,pair<int,int>>>& q){
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int x=it.second.first,y=it.second.second;
        mpp[x][y].insert(it.first->data);
        if(it.first->left){
            q.push({it.first->left,{x-1,y+1}});
        }
        if(it.first->right){
            q.push({it.first->right,{x+1,y+1}});
        }
    }

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

    map<int,map<int,multiset<int>>>mpp;
    queue<pair<Node*,pair<int,int>>> q;
    q.push({root,{0,0}});

    vertical(root,mpp,q);
    vector<vector<int>>ans;
    for(auto it:mpp){
        vector<int>temp;
        for(auto it2:it.second){
            temp.insert(temp.end(),it2.second.begin(),it2.second.end());
        }
        ans.push_back(temp);
    }
    for(auto it : ans){
        for(auto it2 : it){
            cout<<it2<<" ";
        }

    }
}