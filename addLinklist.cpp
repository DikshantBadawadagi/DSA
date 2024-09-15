#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
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


int main() {
Node * head = new Node(1);
head->next = new Node(3);
head->next->next = new Node(5);
head->next->next->next = new Node(7);
head->next->next->next->next = new Node(9);

Node* head1 = new Node(0);
    head1->next = new Node(2);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(6);
    head1->next->next->next->next = new Node(8);

   Node* temp = head;
   Node* temp1 = head1;
    int carry=0;
    Node* dummy = new Node(0);
    Node* dtemp = dummy;

   while(temp!=NULL || temp1!=NULL||carry){
    int sum = 0;
    if(temp!=NULL){
        sum += temp->data;
    }
    if(temp1!=NULL){
        sum += temp1->data;
    }
    sum += carry;

   Node* node = new Node(sum%10);
   dtemp->next = node;
   carry = sum/10;
   dtemp = dtemp->next;

   }
   dummy=dummy->next;
   while(dummy!=NULL){
    cout<<dummy->data<<" ";
   }



    }