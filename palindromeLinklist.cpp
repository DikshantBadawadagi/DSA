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

Node* revLinklist(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    cout<<"yesrev";
    while(curr!=NULL){
        Node* nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
    }
    return prev;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(1);

    Node* slow = head;
    Node* fast = head;


    while(fast->next->next!=NULL){
        slow =slow->next;
        fast=fast->next->next;
    }
    Node* mid = slow->next;
    Node* head1 = revLinklist(mid);
    while(head1!=NULL){
        if(head->data != head1->data){
            return false;
        }
        head1 = head1->next;
        head = head->next;
    }
    return true;
}