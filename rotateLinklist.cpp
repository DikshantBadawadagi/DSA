#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
    }
    Node(int data,Node* next){
        this->data = data;
        this->next = next;
    }

};

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next =new Node(5);

    int k=2;
    Node* temp = head;
    int len = 0;
    while(temp->next!=NULL){temp=temp->next;len++;}
    temp->next = head;
    Node* t = head;
    for(int i=0;i<len-k;i++){
        t = t->next;
    }
    head = t->next;
    t->next = NULL;

    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}