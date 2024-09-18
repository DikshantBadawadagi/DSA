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
int main() {
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(5);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);

    Node* head1 = new Node(0);
    head1->next = new Node(2);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(6);
    head1->next->next->next->next = new Node(8);

    Node* list1 = head;
    Node* list2 = head1;


      Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    // Traverse both lists simultaneously
    while (list1 != nullptr && list2 != nullptr) {
        // Compare elements of both lists and
        // link the smaller node to the merged list
        if (list1->data <= list2->data) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        // Move the temporary pointer
        // to the next node
        temp = temp->next; 
    }

    // If any list still has remaining
    // elements, append them to the merged list
    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }
    // Return the merged list starting 
    // from the next of the dummy node
    Node* temp2 = dummyNode->next;
    while (temp2 != nullptr) {
        // Print the data of the current node
        cout << temp2->data << " "; 
        // Move to the next node
        temp2 = temp2->next; 
    }




}