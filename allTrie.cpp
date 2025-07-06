#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    int prefixCount;
    int wordEndCount;
    vector<TrieNode*>children;
    bool end;

    TrieNode(){
        children.resize(26, NULL);
        end = false;
        prefixCount = 0;
        wordEndCount = 0;
    }
    TrieNode(char data){
        this->data = data;
        children.resize(26, NULL);
        end = false;
        prefixCount = 0;
        wordEndCount = 0;
    }
};

class Trie {
    public:
    TrieNode*root;
    Trie(){
        root = new TrieNode('\0');
    }
    void insert(string word){
        TrieNode* temp = root;
        for(auto ch : word){
            if(temp->children[ch - 'a'] == NULL){
                TrieNode* newNode = new TrieNode(ch);
                temp->children[ch - 'a'] = newNode;
            }
            temp->prefixCount++;
            temp = temp->children[ch - 'a'];
        }
        temp->wordEndCount++;
        temp->end = true;
    }
    bool search(string word){
        TrieNode* temp = root;
        for(auto ch : word){
            if(temp->children[ch -'a'] == NULL)return false;
            temp = temp->children[ch - 'a'];
        }

        return temp->end;
    }

    void deleteWord(string word){
        deleteWordHelper(root, word, 0);
    }
    bool deleteWordHelper(TrieNode* node,string word, int index){
        if(index == word.size()){
            if(!node->end) return false; // Word not found
            node->end = false; // Unmark the end of the word
            return node->children.empty(); // Return true if no children left
        }
        
        char ch = word[index];
        TrieNode* childNode = node->children[ch - 'a'];
        if(childNode == NULL) return false; // Word not found
        
        bool shouldDeleteChild = deleteWordHelper(childNode, word, index + 1);
        
        if(shouldDeleteChild){
            delete childNode; // Delete the child node
            node->children[ch - 'a'] = NULL; // Remove the reference from parent
            return node->end == false && node->children.empty(); // Check if current node can be deleted
        }
        
        return false; // Do not delete this node
    }
    int countWordsWithPrefix(string prefix) {
        TrieNode* temp = root;
        for (char ch : prefix) {
            if (temp->children[ch - 'a'] == NULL) return 0; // Prefix not found
            temp = temp->children[ch - 'a'];
        }
        return temp->prefixCount; // Return the count of words with this prefix
    }
    int countWordsEqualTo(string word) {
        TrieNode* temp = root;
        for (char ch : word) {
            if (temp->children[ch - 'a'] == NULL) return 0; // Word not found
            temp = temp->children[ch - 'a'];
        }
        return temp->wordEndCount; // Return the count of words equal to this word
    }

};
int main() {
    Trie t;//stack allocation
    // // Trie* t = new Trie(); // heap allocation for this we have to do delete(t) at the end
    // Trie* t = new Trie();
    t.insert("hello");
    t.insert("world");
    t.insert("hello");
    cout << t.search("hello") << endl; // Output: 1 (true)
    t.insert("hell");
    cout << t.search("helli") << endl; // Output: 1 (true)
    cout<<t.countWordsWithPrefix("he") << endl; // Output: 3 (hellox2, hell)
    cout<<t.countWordsEqualTo("hello") << endl; // Output: 1
}