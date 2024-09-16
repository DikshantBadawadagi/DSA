#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* child;

    Node(){
        this->data = -1;
        this->next = nullptr;
        this->child = nullptr;

    }

    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->child = nullptr;
    }
    Node(int data,Node* next){
        this->data = data;
        this->next = next;
        this->child = nullptr;
    }
    Node(int data,Node* next,Node* child){
        this->data = data;
        this->next = next;
        this->child = child;
    }
};

Node* mergeList(Node* head, Node* head1){
    Node* dummy = new Node();
    Node* temp = dummy;
    while(head!=NULL && head1!=NULL){
        if(head->data<head1->data){
            temp->child = head;
            temp = temp->child;
            head = head->child;
        }
        else if(head->data>head1->data){
            temp->child = head1;
            temp = temp->child;
            head1= head1->child;
        }
        temp->next = NULL;
    }
    if(head!=NULL){
        temp->child = head;
    }
    else if(head1!=NULL){
        temp->child = head1;
    }
     if(dummy->child){
        dummy->child->next = NULL;
    }
    return dummy->child;
}
Node* flattenLinkedList(Node* head){
    // If head is null or there 
    // is no next node, return head
    if(head == NULL || head->next == NULL){
        return head;
    }

    // Recursively flatten the
    // rest of the linked list
    Node* mergedHead = flattenLinkedList(head->next);
    head = mergeList(head, mergedHead);
    return head;
}
void printLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->child = new Node(10);
    head->next->next = new Node(1);
    head->next->next->child = new Node(7);
    head->next->next->child->child = new Node(11);
    head->next->next->child->child->child = new Node(12);
    head->next->next->next = new Node(4);
    head->next->next->next->child = new Node(9);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->child = new Node(6);
    head->next->next->next->next->child->child = new Node(8);

  Node* flattened = flattenLinkedList(head);
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

return 0;

}