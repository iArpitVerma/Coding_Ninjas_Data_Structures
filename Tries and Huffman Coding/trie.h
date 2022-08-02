#include<iostream>
using namespace std;
class trieNode{
public:
    char data;
    trieNode **children;
    bool isTerminal;

    trieNode(char data){
        this->data = data;
        children = new trieNode*[26];
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};


class trie{
    trieNode* root;

public:
    trie(){
        root = new trieNode('\0');
    }

    void insertWord(trieNode* root,string word){
        // Base Case
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        trieNode *child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            child = new trieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive Call
        insertWord(child,word.substr(1));
    }

    void insertWord(string word){
        insertWord(root,word);
    }

    bool searchWord(trieNode* root,string word){
        // Base Case
        if(word.size() == 0){
            return root->isTerminal;
        }

        // Small Calculation
        int index = word[0] - 'a';
        trieNode* child;
        if(root->children[index] == NULL){
            return false;
        }else{
            child = root->children[index];
        }

        // Recursive Call
        return searchWord(child,word.substr(1));
    }

    bool searchWord(string word){
        return searchWord(root,word);
    }

    void removeWord(trieNode* root, string word){
        // Base Case
        if(word.size() == 0){
            root->isTerminal = false;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        trieNode* child;
        if(root->children[index] == NULL){
            // Word not found
            return;
        }else{
            child = root->children[index];
        }

        // Recursive Calls
        removeWord(child,word.substr(1));

        // Remove child node if useless
        if(child->isTerminal == false){
            for(int i=0;i<26;i++){
                if(child->children[i] != NULL){
                    return;
                }
            }
            delete child;
            root->children[index] = NULL; 
        }
    }

    void removeWord(string word){
        removeWord(root,word);
    }
};