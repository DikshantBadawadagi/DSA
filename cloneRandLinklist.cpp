#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;

    Node(int data){
        this->data = data;
         this->next = NULL;
        this->random = NULL;
    }
    Node(int data,Node* next){
        this->data = data;
        this->next = next;
        this->random = NULL;    }
    Node(int data,Node* next, Node* random){
        this->data = data;
        this->next = next;
        this->random = random;
    }
};


int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next->next->next;
    head->next->next->next->next->random = head->next;

    Node* temp = head;
    while(temp != NULL){
        Node* dummy = new Node(temp->data);
        dummy->next = temp->next;
        temp->next = dummy;
        temp = temp->next->next;
    }
    Node* dum = new Node(-1);
    Node* res = dum;
    Node* temp1 = head;
    while(temp1 != NULL){
        res->next = temp->next;
        temp->next = temp->next->next;
        res = res->next;
        temp=temp->next;
    }
    Node* nhead = dum->next;
    while(nhead!=NULL){
        cout<<nhead->data<<" ";
        nhead = nhead->next;
    }

}