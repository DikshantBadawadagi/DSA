#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
    }
    Node(int data,Node*next){
        this->data=data;
        this->next=next;
    }
};
int main(Node* head,Node* head1) {
    Node* temp=head;
    Node* temp1=head1;
 while(temp != temp1){
        if (temp == NULL) {
        temp = head1;
    } else {
        temp = temp->next;
    }
    
    if (temp1 == NULL) {
        temp1 = head;
    } else {
        temp1 = temp1->next;
    }

 }
 cout<<temp->data;

}