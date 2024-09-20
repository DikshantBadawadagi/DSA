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
    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
};

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = head->next->next;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){

        fast = fast->next->next;
        slow =slow->next;
        if(slow==fast){
            slow = head;
            while(slow!=fast){
            slow = slow->next;
            fast=fast->next;
            }
            cout<<slow->data;
            return 0;
        }
    }
}