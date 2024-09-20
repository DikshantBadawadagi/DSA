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

Node* kthNode(Node* temp,int k){
    Node* temp1 = temp;
    k-=1;
    while(temp1!=NULL && k>0){
        temp1 = temp1->next;
        k--;
    }
    return temp1;
}
Node* revLinklist(Node* head){
       Node* prev =NULL;
    Node* temp = head;
    while(temp!=NULL){
    Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;   
   }
    return prev;
}
int main() {
Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next->next->next = new Node(10); 

    Node* temp = head;
    int a;
    cin>>a;
    while(temp!=NULL){
    Node* k = kthNode(head,a);
    Node* nextptr = k->next;
    k->next = NULL;
    Node* h1 = revLinklist(head);
    Node* prev = temp;
    temp = nextptr;
    


    }
    


}