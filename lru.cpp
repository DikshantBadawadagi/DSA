#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public: 
    int key;
    int value;
    Node* next;
    Node* prev;
    
    Node(int key,int value){
        this->key = key;
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LRUCache{
    unordered_map<int,Node*>mpp;
    int capacity;
    Node* head;
    Node* tail;
    public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void insert(int key,int value){
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->value = value;
            deleteNode(node);
            insertAtHead(node);
        }else{
            if(mpp.size() >= capacity){
                Node* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
                delete node;
            }
            Node* node = new Node(key,value);
            mpp[key] = node;
            insertAtHead(node);
            }
        }

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void insertAtHead(Node* node) {
        node->next = head->next;
        node->next->prev = node;
        node->prev = head;
        head->next = node;
    }
    int get(int key) {
        if(mpp.find(key) == mpp.end()) {
            return -1;
        }
        Node* node = mpp[key];
        deleteNode(node);
        insertAtHead(node);
        return node->value;
        }
};


int main() {
    LRUCache cache(2);
    cache.insert(1, 1);
    cache.insert(2, 2);
    cout << cache.get(1) << endl; // returns 1
    cache.insert(3, 3); // evicts key 2
    cout << cache.get(2) << endl; // returns -1 (not found)
    cache.insert(4, 4); // evicts key 1
    cout << cache.get(1) << endl; // returns -1 (not found)
    cout << cache.get(3) << endl; // returns 3
    cout << cache.get(4) << endl; // returns 4
    return 0;
}