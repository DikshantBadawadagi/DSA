
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    // Data stored in the node
    int data;   
    
    // Pointer to the next node in the list
    Node* next;      

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    Node* prev =NULL;
    Node* temp = head;
    while(temp!=NULL){
    Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;   
   }
     Node* temp1 = prev;
    while (temp1 != NULL) {
        cout << temp1->data << " ";
        temp1= temp1->next;
    }
}