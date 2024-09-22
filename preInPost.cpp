#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node*left;
    Node*right;

    Node(int data): data(data),left(nullptr),right(nullptr){}
};

void preinpost(Node* root,vector<int>& pre,vector<int>& in,vector<int>& post){
    stack<pair<Node*,int>>st;
    if(root == NULL) return;
    st.push({root,1});
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second+=1;
            st.push(it);
            if(it.first->left!=NULL){
                st.push({it.first->left,1});
            }
        }
        if(it.second == 2){
            in.push_back(it.first->data);
            it.second+=1;
            st.push(it);
            if(it.first->right !=NULL){
                st.push({it.first->right,1});
            }
        }
        if(it.second == 3){
            post.push_back(it.first->data);
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

    vector<int> pre,in,post;
    preinpost(root,pre,in,post);
    for(auto i:pre) cout<<i<<" ";
    cout<<endl;
    for(auto i:in) cout<<i<<" ";
    cout<<endl;
    for(auto i:post) cout<<i<<" ";
}